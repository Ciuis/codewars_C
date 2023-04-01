// Write function RemoveExclamationMarks which removes all exclamation marks from a given string.

// Write resulting string into buffer pointed by str_out

void remove_exclamation_marks(const char *str_in, char *str_out) {
    int j = 0;
    for (int i = 0; str_in[i]; ++i) {
        if (str_in[i] != '!') str_out[j++] = str_in[i];
    }
    str_out[j] = 0;
}

/*
void remove_exclamation_marks(const char *str_in, char *str_out) {
    while (*str_out = *str_in++)
        str_out += *str_out != '!';
}*/
