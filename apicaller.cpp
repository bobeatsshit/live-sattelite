#include "apicaller.h"
#include <iostream>

// Callback functie om de respons op te slaan
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

HttpClient::HttpClient() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init(); // Initialiseer de curl lidvariabele
}

HttpClient::~HttpClient() {
    if (curl) curl_easy_cleanup(curl); // Opruimen van curl
    curl_global_cleanup();
}

std::string HttpClient::get(const std::string& mode, const std::string& satID, const std::string& APIKEY) {
    if (!curl) {
        throw std::runtime_error("Failed to initialize CURL");
    }

    std::string url = "https://api.n2yo.com/rest/v1/satellite/" + mode + "/" + satID + "/&apiKey=" + APIKEY;
    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }

    return response;
}
