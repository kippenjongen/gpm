#include <stdlib.h>
#include "check_gpm.h"
#include "../src/funcs.h"

#include <stdio.h>

START_TEST(check_funcs_jsmn){
	jsmn_parser p;
	jsmntok_t t[128];
	char* s = "{\"menu\": {\"id\": \"file\",\"value\": \"File\",\"popup\": {\"menuitem\": [{\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"},{\"value\": \"Open\", \"onclick\": \"OpenDoc()\"},{\"value\": \"Close\", \"onclick\": \"CloseDoc()\"}]}}}";

	jsmn_init(&p);
	int tokens = jsmn_parse(&p, s, strlen(s), t, 128);
	
	jsmnstring *strings;
	strings = (jsmnstring*) malloc((tokens + 1) * sizeof(jsmnstring));
	
	for(int i = 0; i < tokens; i++){
		strings[i] = jsmntok_to_string(&t[i], &s);
//		printf("%.5s", strings[i].string.string);
	}
	
	printf("%s\n", strings[1].string.string);
	printf("%i\n", strings[1].string.size);

	ck_assert(1 == 1);

}
END_TEST

Suite* check_funcs_suite(void){
    Suite *s;
    TCase *tc_core;

    s = suite_create("funcs");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, check_funcs_jsmn);
	suite_add_tcase(s, tc_core);

    return s;
}
