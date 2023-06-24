// Arc AUR Helper

#include <stdio.h> // printf
#include <stdlib.h> // Standard Library
#include <curl/curl.h> // libcurl


int main(int argc, char* argv[]) {
	curl_global_init(CURL_GLOBAL_DEFAULT);
	if (argc > 1) {
		if (argv[1] = "-S") {
			if (argc > 2) {
				printf("\033[1;94m::\033[0;0m Searching for package \"%s\"...", argv[2]);
				CURL *curl = curl_easy_init();
				curl_easy_setopt(curl, CURLOPT_URL, "https://aur.archlinux.org/rpc/v5/info/visual-studio-code-bin");
				struct curl_slist *cheaderlist = NULL;
				cheaderlist = curl_slist_append(cheaderlist, "accept: application/json");
				curl_easy_setopt(curl, CURLOPT_HTTPHEADER, cheaderlist);
				CURLcode res = curl_easy_perform(curl);

				
				if (res == CURLE_OK) {
					printf("\n\033[1;92m::\033[0;0m Package found!\n");
				} else {
					printf("\n\033[1;91m!\033[0;0m Error fetching data from the AUR RPC, check your internet connection.");
				}
				curl_slist_free_all(cheaderlist);
				curl_easy_cleanup(curl);
			} else {
				printf("\033[1;91m!\033[0;0m No package provided!");
			}
		}
	} else {
		printf("\033[0;92mUsage\033[0;0m: \033[0;94marc\033[0;0m [package] [-skipkey]");
		printf("\n \033[4;94mpackage\033[0;0m: \033[1;94mpackage\033[0;0m to be installed");
		printf("\n \033[4;94m-skipkey\033[0;0m: skip MAKEPKG's \033[1;94mkey\033[0;0m Check");
	}
}
