/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** call_API
*/

#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>
#include "include/gorilla.h"

int call_API(void)
{
     CURL *curl;
    CURLcode response;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://type.fit/api/quotes");

        response = curl_easy_perform(curl);

        if(response != CURLE_OK) {
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(response));
        } else {
            printf("%d", response);
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}

char *open_file(void)
{
    char *buff;
    int len;
    len = read(0, buff, 10000);
    if (len <= 0)
        return NULL;
    buff[len + 1] = '\0';
    return buff;
}

char *get_quote(void)
{
    char *buff = open_file();

}

int main(void)
{
    call_API();
    return 0;
}
