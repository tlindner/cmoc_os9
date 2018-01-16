#include <cgfx.h>

void test_overlay()
{
    _cgfx_owset(1, 1, 20, 10, 30, 8, 4, 6);
    
    char *message = "Overlay here!";
    int length = strlen(message);
    _os_write(1, message, &length);
    
    int ticks = 60*2;
    _os9_sleep(&ticks);

    _cgfx_owend(1);
}

int main(int argc, char **argv)
{
	test_overlay();

	return 0;
}
