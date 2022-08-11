#include<stdio.h>
#include <dbus/dbus.h>
//#include <dbus/dbus-glib.h>

int main(void)
{
    DBusError error;
    DBusConnection *conn;
    dbus_error_init(&error);
    conn = dbus_bus_get(DBUS_BUS_SESSION, &error);
    dbus_connection_set_exit_on_disconnect(conn, TRUE);
    if(!conn)
    {
        fprintf(stderr, "%s: %s\n", error.name, error.message);
        return 1;
    }
    printf("%s\n", dbus_bus_get_unique_name(conn));
    dbus_bus_set_unique_name(conn, "MyDBusConnection");
    printf("%s\n", dbus_bus_get_unique_name(conn));

    DBusMessage *dmsg;
    dmsg = dbus_message_new_method_call("org.freedesktop.DBus", "/org/freedesktop/DBus", "org.freedesktop.DBus.Peer", "GetMachineId");

    DBusMessageIter iter;
    dbus_message_iter_init(dmsg, &iter);
    int current_type;
    while ((current_type = dbus_message_iter_get_arg_type (&iter)) != DBUS_TYPE_INVALID)
    {
        printf("In current type %d\n",current_type);
        dbus_message_iter_next (&iter);
    }

    if (DBUS_TYPE_INVALID != dbus_message_iter_get_arg_type(&iter))
    {
        char* str = NULL;
        dbus_message_iter_get_basic(&iter, &str);//this function is used to read basic dbus types like int, string etc. 
        printf("In If statement\n");
        printf("%s\n", str);
    }
    return 0;
}
