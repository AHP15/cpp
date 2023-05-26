#include <iostream>

struct Website {
    std::string name { "learcpp" };
};

Website web {};

struct Advertising {
    int ads_number {};
    int ad_clicks_number {};
    double avarage_click_earning {};
    Website* ptr { &web };
};

void printAdvertising(const Advertising& ads) {
    std::cout << "The number of ads: " << ads.ads_number << '\n';
    std::cout << "The number of clicks: " << ads.ad_clicks_number << '\n';
    std::cout << "The avarge earning per click: " << ads.avarage_click_earning << '\n';
    std::cout << "The total earning of today: " << ads.ad_clicks_number * ads.avarage_click_earning << '\n';
}

int main() {
    Advertising website {};
    std::cout << "Enter the number of ads: ";
    std::cin >> website.ads_number;

    std::cout << "Enter the number of clicks: ";
    std::cin >> website.ad_clicks_number;

    std::cout << "Enter the avarege earning per click: ";
    std::cin >> website.avarage_click_earning;

    printAdvertising(website);

    Advertising* ptr { &website };

    std::cout << ptr->ptr->name << '\n';
    return 0;
}