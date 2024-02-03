#include "maccel.h"

// historic mouse report linked list element
typedef struct _hist_report_mouse_t {
    mouse_xy_report_t x;
    mouse_xy_report_t y;
    uint32_t timestamp;
    struct _hist_report_mouse_t *next;
} hist_report_mouse_t;

// historic mouse report linked list root
static hist_report_mouse_t *past_reports = NULL;

void hist_report_add(report_mouse_t report) {
    // Create new hist report
    hist_report_mouse_t *hr = malloc(sizeof(hist_report_mouse_t));
    hr->x = report.x;
    hr->y = report.y;
    hr->timestamp = timer_read();

    // prepend to list
    hr->next = past_reports;
    past_reports = hr;

    reports_added += 1;
    // if(past_reports == NULL) {
    //     past_reports = hr;
    // } else {
    //     hist_report_mouse_t *cur;
    //     cur = past_reports;
    //     while (cur->next != NULL) {
    //         cur = cur->next;
    //     }
    //     cur->next = hr;
    // }
}

bool remove_last(hist_report_mouse_t *head) {
    // if no element, abort
    if(head == NULL) {
        return false;
    } else if (head->next == NULL) {
        // if single element, remove it
        free(head);
        reports_freed += 1;
        return true;
    } else {
        // iterate to last-but-one elem
        hist_report_mouse_t *cur = head;
        while (cur->next->next != NULL) {
            cur = cur->next;
        }

        /* now current points to the second to last item of the list, so let's remove current->next */
        free(cur->next);
        reports_freed += 1;
        cur->next = NULL;
        return true;
    }
}

void hist_reports_cull(void) {
    // iterate through reports, find cull time
    hist_report_mouse_t *cur; // current element for iterating
    hist_report_mouse_t *cut = NULL; // Element to start discarding at
    cur = past_reports;

    // iterate and find cut-off point
    if (cur != NULL) {
        while(cur->next != NULL) {
            if(timer_elapsed(cur->next->timestamp) > MACCEL_HISTORY_TIME) { // is the next element old enough to cull?
                cut = cur->next; // save next element for discarding
                cur->next = NULL; // cut off the list here, everything behind this is older
            } else {
                cur = cur->next;
            }
        }
    }

    // dispose cut data, if any 
    if(cut!=NULL) {
        while(cut->next != NULL) {
            remove_last(cut);
        }
        free(cut);
        reports_freed+=1;
        cut=NULL;
    }
}


uint16_t hist_reports_count(void) {
    uint16_t             hc  = 0;
    hist_report_mouse_t *cur = past_reports;
    if (cur != NULL) {
        hc += 1;
        while (cur->next != NULL) {
            cur = cur->next;
            hc += 1;
        }
    }
    return hc;
}
