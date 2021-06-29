#include <iostream>
#include <string>
#include <fstream>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

using std::operator""s;
using namespace std::literals::string_literals;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                   V1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

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

*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                   V2
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace {
    unsigned ln = 1;
    auto Color(int n, const std::string& s) { return "\33[38;5;"+std::to_string(n)+'m'+s+"\33[m"; }
    auto Line(int l) { int m=l-ln; ln=l; return "\r"+(m<0?"\33["+std::to_string(-m)+'A':std::string(m,'\n')); }
    void download(const std::string& url, const std::string& filename, unsigned line){
        std::ofstream of(filename);

        cURLpp::Easy request;
        request.setOpt(cURLpp::Options::Url(url));
        request.setOpt(cURLpp::Options::NoProgress(false));
        request.setOpt(cURLpp::Options::FollowLocation(true));
        request.setOpt(cURLpp::Options::ProgressFunction([&](std::size_t total, std::size_t done, auto...){
            std::cout << Line(line) << Color(143, filename + ": ") << done << " of " << total
                << " bytes recibidos (" << int(total ? done*100./total : 0) << "%)" << std::flush;
            return 0;
        }));

        request.setOpt(cURLpp::Options::WriteFunction([&](const char* p, std::size_t size, std::size_t nmemb){
            of.write(p, size*nmemb);
            return size*nmemb;
        }));
        request.perform();
    }
    auto root = "http://localhost:3490/"s;
}

int main(int argc, char* argv[]){
    (void)argc;
    (void)argv;
    cURLpp::initialize();
    unsigned line = 1;
    for(const auto& p: {"8859-1.TXT"s, "8859-2.TXT"s, "8859-3.TXT"s, "8859-4.TXT"s, "8859-5.TXT"s,
                        "8859-6.TXT"s, "8859-7.TXT"s, "8859-8.TXT"s, "8859-9.TXT"s, "8859-10.TXT"s,
                        "8859-11.TXT"s,"8859-13.TXT"s,"8859-14.TXT"s,"8859-15.TXT"s,"8859-16.TXT"s})
    {
        download(root+p, p, line++);
    }
    std::cout << Line(line) << std::endl;
    return 0;
}