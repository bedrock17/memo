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

  char * p = page;
  char * tmpPage = (char*)malloc(page_sz);

  if (tmpPage == NULL)
    return NULL;

  char * startp = page;
  char * endp = page;
  char buf[128];

  memset(tmpPage, 0, page_sz);
  while (p = strstr(p, MARKSTRING)) {
    
    //MARKSTRING 이 등장하기 이전까지의 문자열복사
    strncat(tmpPage, endp, p-endp);

    DEBUGF("====!!!=== %d \n", __LINE__);
    DEBUGF("%s\n", tmpPage);
    DEBUGF("====!!!====\n");

    DEBUGF(p);

    p+=strlen(MARKSTRING);
    startp = p;
    endp = strstr(startp, MARKSTRING);
  
    if (endp != NULL) {

      *endp = 0;
      endp += strlen(MARKSTRING);
      snprintf(buf, sizeof(buf), startp);

      for (int i = 0; i < KEYMAX; i++) {
        if (strcmp(startp, res_key[i])){
          snprintf(buf, sizeof(buf), langtable[lang][i]);
        }
      }

      //언어에 가져온 문자
      strcat(tmpPage, buf);
      DEBUGF("===========\n");
      DEBUGF("%s\n", tmpPage);
      DEBUGF("===========\n");
    }

    p = endp;
  }
  
  strcat(tmpPage, endp);
  
  memcpy(page, tmpPage, page_sz);
  free(tmpPage);
  return page;
  
  //만약 처리하는도중 발생하는 예외가 있다면...
  err:
  free(tmpPage);
  return NULL;
} 

#define TESTBUF_SIZE 1024
int main() {

  char org_page[TESTBUF_SIZE] =
  "<html>\n"
  " <head></head>\n"
  " <body>\n"
  "   <h1>##hello##</h1>\n"
  "   <h2>##good##</h2>\n"
  " </body>\n"
  "</html>\n";

  char test_page[TESTBUF_SIZE];
  strcpy(test_page, org_page);
  replace_res_page(test_page, sizeof(test_page), LANG_KOR);
  printf("\ntestpage : \n%s \n", test_page);

  strcpy(test_page, org_page);
  replace_res_page(test_page, sizeof(test_page), LANG_ENG);
  printf("\ntestpage : \n%s \n", test_page);

  return 0;
}
