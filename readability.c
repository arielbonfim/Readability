#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
float count_letters(string text);
float count_words(string text);
float count_sentences(string text);
int main(void)
{
    string text = get_string("Text: ");
    float L = count_letters(text) / count_words(text) * 100; //use functions to declare formula's incognito
    float S = count_sentences(text) / count_words(text) * 100; //use functions to declare formula's incognito
    int index = round(0.0588 * L - 0.296 * S - 15.8);//Coleman-Liau index formula

    if (index < 1)//test conditionals
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

float count_letters(string text)
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            n ++;
        }
    }
    return n;
}
float count_words(string text)
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        int ascii_code = text[i];
        if (ascii_code == 32)
        {
            n ++;
        }
    }
    n ++;
    return n;
}
float count_sentences(string text)
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        int ascii_code = text[i];
        if (ascii_code == 46 || ascii_code == 33 || ascii_code == 63)
        {
            n++;
        }
    }
    return n;
}
