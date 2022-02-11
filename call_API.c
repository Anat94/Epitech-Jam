/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** call_API
*/

#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>

int call_API(void) {
    CURL *curl;
    CURLcode response;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.quotable.io/random?tags=famous-quotes");

        response = curl_easy_perform(curl);

        if(response != CURLE_OK) {
            fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(response));
        } else {
            printf("%i\n", response);
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
    len = read(0, buff, 200);
    if (len <= 0)
        return NULL;
    buff[len + 1] = '\0';
    return buff;
}

int main(void)
{
    call_API();
    printf("%s\n", open_file());
    return 0;
}
