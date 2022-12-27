void pentryuser(char str[], game edata, game user)
{
    // data id user
    strcpy(edata.id_user, getkata());
    // data username
    inc(str);
    if (eop(str) == 0) // cek op
    {
        strcpy(edata.username, getkata());
        // data id char
        inc(str);
        if (eop(str) == 0) // cek eop
        {
            strcpy(edata.id_char, getkata());
            // data level
            inc(str);
            if (eop(str) == 1) // cek eop
            {
                strcpy(edata.level, getkata());
                // memasukkan data ke tipe terstruktur
                entryuser(edata, user);
                printf("Perintah yang dijalankan adalah\nENTRY user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                writeuser("user.dat", user);
            }
            else
            {
                printf("Silahkan memperbaiki query!\n");
            }
        }
        else
        {
            printf("Silahkan memperbaiki query!\n");
        }
    }
    else
    {
        printf("Silahkan memperbaiki query!\n");
    }
}

void pupdateuser(char str[], game edata, game user, int cidx)
{
    // data id user
    strcpy(edata.id_user, getkata());
    // data username
    inc(str);
    if (eop(str) == 0) // cek eop
    {
        strcpy(edata.username, getkata());
        // data id char
        inc(str);
        if (eop(str) == 0) // cek eop
        {
            strcpy(edata.id_char, getkata());
            // data level
            inc(str);
            if (eop(str) == 1) // cek eop
            {
                strcpy(edata.level, getkata());
                // memasukkan data ke tipe terstruktur
                updateuser(edata, user, cidx);
                printf("Perintah yang dijalankan adalah\nUBAH user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                writeuser("user.dat", user);
            }
            else
            {
                printf("Silahkan memperbaiki query!\n");
            }
        }
        else
        {
            printf("Silahkan memperbaiki query!\n");
        }
    }
    else
    {
        printf("Silahkan memperbaiki query!\n");
    }
}

void pdeluser(char str[], gane edata, game user, int cidx)
{
    // data id user
    strcpy(edata.id_user, getkata());
    // data username
    inc(str);
    if (eop(str) == 0) // cek eop
    {
        strcpy(edata.username, getkata());
        // data id char
        inc(str);
        if (eop(str) == 0) // cek eop
        {
            strcpy(edata.id_char, getkata());
            // data level
            inc(str);
            if (eop(str) == 1) // cek eop
            {
                strcpy(edata.level, getkata());
                // memasukkan data ke tipe terstruktur
                deluser(user, cidx);
                printf("Perintah yang dijalankan adalah\nHAPUS user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                writeuser("user.dat", user);
            }
            else
            {
                printf("Silahkan memperbaiki query!\n");
            }
        }
        else
        {
            printf("Silahkan memperbaiki query!\n");
        }
    }
    else
    {
        printf("Silahkan memperbaiki query!\n");
    }
}

void pentrychar(char str[], game edata, game character)
{
    // data id char
    strcpy(edata.id_char, getkata());
    inc(str);
    if (eop(str) == 0) // cek op
    {
        // data job
        strcpy(edata.job_char, getkata());
        inc(str);
        if (eop(str) == 1) // cek eop
        {
            // data skill
            strcpy(edata.skill, getkata());
            // memasukkan data ke tipe terstruktur
            entrychar(edata, character);
            printf("Perintah yang dijalankan adalah\nENTRY character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
            writechar("character.dat", character);
        }
        else
        {
            printf("Silahkan memperbaiki query!\n");
        }
    }
    else
    {
        printf("Silahkan memperbaiki query!\n");
    }
}

void pupdatechar(char str[], game edata, game character, int cidx)
{
    // data id char
    strcpy(edata.id_char, getkata());
    inc(str);
    if (eop(str) == 0) // cek eop
    {
        // data job
        strcpy(edata.job_char, getkata());
        inc(str);
        if (eop(str) == 1) // cek eop
        {
            // data skill
            strcpy(edata.skill, getkata());
            // memasukkan data ke tipe terstruktur
            updatechar(edata, character, cidx);
            printf("Perintah yang dijalankan adalah\nUBAH character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
            writechar("character.dat", character);
        }
        else
        {
            printf("Silahkan memperbaiki query!\n");
        }
    }
    else
    {
        printf("Silahkan memperbaiki query!\n");
    }
}

void pdelchar(char str[], game edata, game character, int cidx)
{
    // data id char
    strcpy(edata.id_char, getkata());
    inc(str);
    if (eop(str) == 0) // cek eop
    {
        // data job
        strcpy(edata.job_char, getkata());
        inc(str);
        if (eop(str) == 1) // cek eop
        {
            // data skill
            strcpy(edata.skill, getkata());
            // memasukkan data ke tipe terstruktur
            delchar(character, cidx);
            printf("Perintah yang dijalankan adalah\nUBAH character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
            writechar("character.dat", character);
        }
        else
        {
            printf("Silahkan memperbaiki query!\n");
        }
    }
    else
    {
        printf("Silahkan memperbaiki query!\n");
    }
}