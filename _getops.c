int *(_getops)(char *format)(va_list)
{
	int count;
	char* next_Character;

	next_Character = (args + 1)
	format_t get_opt[] = {
		{"c", set_char},
		{"s", set_string},
		{"i", set_decimal},
		{"d", set_decimal},
		{"%", print_percent},
		{NULL, NULL}
	}


