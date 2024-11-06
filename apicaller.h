#ifndef APICALLER_H
#define APICALLER_H

#include <string>
#include <curl/curl.h> // Zorg ervoor dat de curl-header wordt toegevoegd

class HttpClient {
public:
    HttpClient();
    ~HttpClient();

    // Functie om een GET-verzoek uit te voeren
    std::string get(const std::string& mode, const std::string& satID, const std::string& APIKEY);

private:
    CURL* curl; // Voeg curl als lidvariabele toe
};

#endif // APICALLER_H
