#include<stdio.h>
#include <dbus/dbus.h>

int main(void)
{
    DBusError error;
    DBusConnection *conn;
    dbus_error_init(&error);
    conn = dbus_bus_get(DBUS_BUS_SYSTEM, &error);
    if(!conn)
    {
        fprintf(stderr, "%s: %s\n", error.name, error.message);
        return 1;
    }
    return 0;
}
