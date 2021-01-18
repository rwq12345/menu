#include<string.h>
#include "menu.h"

menu_node_item_t log_menus[] = {
    LEVEL(1,"log",default_action)
        LEVEL(2,"log_info",default_action)
        LEVEL(2,"test_printf_main",default_action)
        LEVEL(2,"test_log_same_tag",default_action)
        LEVEL(2,"test_log_different_tag",default_action)
};

menu_node_item_t osi_menus[] = {
    LEVEL(1,"osi",default_action)
        LEVEL(2,"test_get_pid",default_action)
        LEVEL(2,"test_get_tid",default_action)
        LEVEL(2,"test_get_pid_name",default_action)
        LEVEL(2,"test_epoll",default_action)
};

menu_node_item_t time_menus[] = {
    LEVEL(1,"time & timer",default_action)
        LEVEL(2,"time_info",default_action)
        LEVEL(2,"date_time",default_action)
            LEVEL(3,"test_date_time_second",default_action)
            LEVEL(3,"test_date_time_microsecond",default_action)
            LEVEL(3,"test_date_time_nanasecond",default_action)
        LEVEL(2,"sleep",default_action)
            LEVEL(3,"test_sleep_second",default_action)
            LEVEL(3,"test_sleep_millisecond",default_action)
            LEVEL(3,"test_sleep_microsecond",default_action)
            LEVEL(3,"test_sleep_nanosecond",default_action)
            LEVEL(3,"test_sleep_nanosecond_clock",default_action)
        LEVEL(2,"timer",default_action)
            LEVEL(3,"test_alarm_signal_timer",default_action)
};

int main(int argc,char *argv[]){
    init_menu();

    ADD_MENU(log_menus);
    ADD_MENU(osi_menus);
    ADD_MENU(time_menus);

    run_menu();
    return 0;   
}
