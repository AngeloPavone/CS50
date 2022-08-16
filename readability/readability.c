#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define DEBUG 1

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);
float grade_level(float letters, float words, float sentences);
void print_grade(float grade);
string get_input_text();

int main(void)
{
    string text = get_input_text();
    float letters = letter_count(text);
    float words = word_count(text);
    float sentences = sentence_count(text);
    float grade = grade_level(letters, words, sentences);
    print_grade(grade);
    return 0;
}

float grade_level(float letters, float words, float sentences)
{
    // simply doing the calculations
    float letters_per_100 = letters / words * 100;
    float sentences_per_100 = sentences / words * 100;
    float grade_level = 0.0588 * letters_per_100 - 0.296 * sentences_per_100 - 15.8;

    // debug prints
    if (DEBUG)
    {
        printf("Letters %d\n", (int)letters);
        printf("Words %d\n", (int)words);
        printf("Sentences %d\n", (int)sentences);
        printf("Avg letters per 100 words %f\n", letters_per_100);
        printf("Avg sentences per 100 words %f\n", sentences_per_100);
        printf("Grade %f\n", grade_level);
    }

    return grade_level;
}

int sentence_count(string text)
{
    // looping through and incrementing the sentence count at every ! . ?
    int sentence_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sentence_count++;
        }
    }
    return sentence_count;
}

string get_input_text()
{
    // prompts user for input text
    string text = get_string("Text: ");
    return text;
}

int letter_count(string text)
{
    // gets the letter count by checking if the ascii ID is between lowercase a-z and capital A-Z if it is  increment letter_count
    int letter_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letter_count++;
        }
    }
    return letter_count;
}

int word_count(string text)
{
    // calculates the word count by counting every space starting at 1 because there will always been 1 less space then words
    int word_count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            word_count++;
        }
    }
    return word_count;
}

void print_grade(float grade)
{
    // prints the result of the grade calculation rounded to the nearest int unless less than 1
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(grade));
    }
}