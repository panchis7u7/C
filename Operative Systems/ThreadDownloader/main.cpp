#include <iostream>
#include <string>
#include <fstream>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

namespace {
    void download(const std::string& url, const std::string& filename){
        std::ofstream of(filename);

        cURLpp::Easy request;
        request.setOpt(cURLpp::Options::Url(url));
        request.setOpt(cURLpp::Options::NoProgress(false));
        request.setOpt(cURLpp::Options::FollowLocation(true));
        request.setOpt(cURLpp::Options::ProgressFunction([&](std::size_t total, std::size_t done, auto...){
            std::cout << "\r" << done << " of " << total
                << " bytes recibidos (" << int(total ? done*100./total : 0) << "%)" << std::flush;
            return 0;
        }));

        request.setOpt(cURLpp::Options::WriteFunction([&](const char* p, std::size_t size, std::size_t nmemb){
            of.write(p, size*nmemb);
            return size*nmemb;
        }));
        request.perform();
    }
}

int main(int argc, char* argv[]){
    cURLpp::initialize();
    download("http://iki.fi/bisqwit/ctu85/NamesList.txt", "NamesList.txt");
    return 0;
}