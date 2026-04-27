#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MARKSTRING "##"

#define DEBUGF 
// #define DEBUGF printf

const char* res_key[] = {
    "hello",
    "good"
};

#define KEYMAX (sizeof(res_key)/sizeof(char*))

const char * res_kor[] = {
    "안녕",
    "좋아"
};
const char * res_eng[] = {
    "hello~",
    "good!"
};

enum {
    LANG_ENG,
    LANG_KOR
};

const char ** langtable[] = {
    res_eng,
    res_kor
};

char * replace_res_page(char * page, size_t page_sz, int lang) {
    if (page == NULL || page_sz == 0) return NULL;

    char *tmpPage = (char*)malloc(page_sz);
    if (tmpPage == NULL) return NULL;

    memset(tmpPage, 0, page_sz);
    
    char *p = page;
    char *last_p = page;
    
    while ((p = strstr(p, MARKSTRING)) != NULL) {
        
        //MARKSTRING 이 등장하기 이전까지의 문자열복사
        size_t len = p - last_p;
        strncat(tmpPage, last_p, len);
        
        p += strlen(MARKSTRING);
        char *endp = strstr(p, MARKSTRING);
        
        if (endp != NULL) {
            size_t key_len = endp - p;
            char key_buf[64] = {0,};
            if (key_len < sizeof(key_buf)) {
                strncpy(key_buf, p, key_len);
                
                const char *replace_val = key_buf;
                for (int i = 0; i < KEYMAX; i++) {
                    if (strcmp(key_buf, res_key[i]) == 0) {
                        replace_val = langtable[lang][i];
                        break;
                    }
                }
                //언어에 가져온 문자
                strncat(tmpPage, replace_val, page_sz - strlen(tmpPage) - 1);
            }
            p = endp + strlen(MARKSTRING);
            last_p = p;
        } else {
            break;
        }
    }
    
    strcat(tmpPage, last_p);
    
    strncpy(page, tmpPage, page_sz - 1);
    page[page_sz - 1] = '\0';
    
    free(tmpPage);
    return page;

    //만약 처리하는도중 발생하는 예외가 있다면...
    err:
    free(tmpPage);
    return NULL;
} 

#define TESTBUF_SIZE 1024
int main() {
    char org_page[] =
        "<html>\n"
        " <head></head>\n"
        " <body>\n"
        "   <h1>##hello##</h1>\n"
        "   <h2>##good##</h2>\n"
        " </body>\n"
        "</html>\n";

    char test_page[TESTBUF_SIZE];

    strncpy(test_page, org_page, sizeof(test_page));
    replace_res_page(test_page, sizeof(test_page), LANG_KOR);
    printf("--- KOREAN ---\n%s\n", test_page);

    strncpy(test_page, org_page, sizeof(test_page));
    replace_res_page(test_page, sizeof(test_page), LANG_ENG);
    printf("--- ENGLISH ---\n%s\n", test_page);

    return 0;
}
