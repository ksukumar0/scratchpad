#include<stdio.h>
#include <dbus/dbus.h>
//#include <dbus/dbus-glib.h>

int main(void)
{
    DBusError error;
    DBusConnection *conn;
    dbus_error_init(&error);
    conn = dbus_bus_get(DBUS_BUS_SYSTEM, &error);
    dbus_connection_set_exit_on_disconnect(conn, TRUE);
    if(!conn)
    {
        fprintf(stderr, "%s: %s\n", error.name, error.message);
        return 1;
    }
    printf("%s\n", dbus_bus_get_unique_name(conn));
    dbus_bus_set_unique_name(conn, "MyDBusConnection");
    printf("%s\n", dbus_bus_get_unique_name(conn));

    //dbus_connection_close(conn);

    return 0;
}
