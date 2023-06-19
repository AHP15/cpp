#include <iostream>
#include <array>
#include <algorithm>
#include <ctime>
#include <random>
#include <cassert>

enum class CardRanks {
    two,
    three,
    four,
    five,
    six,
    seven,
    hight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,

    max_ranks
};

enum class CardSuits {
    clubs,
    diamonds,
    hearts,
    spades,

    max_suits,
};

struct Card {
    CardRanks rank {};
    CardSuits suit {};
};

void printCard(Card& card) {
    using enum CardRanks;
    using enum CardSuits;

    switch (card.rank) {
    case two:
        std::cout << '2';
        break;
    case three:
        std::cout << '3';
        break;
    case four:
        std::cout << '4';
        break;
    case five:
        std::cout << '5';
        break;
    case six:
        std::cout << '6';
        break;
    case seven:
        std::cout << '7';
        break;
    case hight:
        std::cout << '8';
        break;
    case nine:
        std::cout << '9';
        break;
    case ten:
        std::cout << "10";
        break;
    case jack:
        std::cout << 'J';
        break;
    case queen:
        std::cout << 'G';
        break;
    case king:
        std::cout << 'K';
        break;
    case ace:
        std::cout << 'A';
        break;
    default:
        break;
    }

    switch (card.suit) {
    case clubs:
        std::cout << 'C';
        break;
    case diamonds:
        std::cout << 'D';
        break;
    case spades:
        std::cout << 'S';
        break;
    case hearts:
        std::cout << 'H';
        break;
    default:
        break;
    }
};

constexpr int numberOfCards { 52 };
using Deck = std::array<Card, numberOfCards>;
using Index = Deck::size_type;
Deck createDeck() {
    using enum CardRanks;
    using enum CardSuits;

    Deck deck {};
    Index index { 0 };
    for (int i { 0 }; i < static_cast<int>(max_suits); ++i) {
        for (int j { 0 };  j < static_cast<int>(max_ranks); ++j) {
            deck[index].suit = static_cast<CardSuits>(i);
            deck[index].rank = static_cast<CardRanks>(j);
            ++index;
        }
    };
    return deck;
};

void printDeck(const Deck& deck) {
    for (auto card: deck) {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
};

void shuffleDeck(Deck& deck) {
    // mt is static so it only gets seeded once.
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(deck.begin(), deck.end(), mt);
};

int getCardValue(Card& card) {
    using enum CardRanks;
    switch(card.rank) {
    case two: return 2;
    case three: return 3;
    case four: return 4;
    case five: return 5;
    case six: return 6;
    case seven: return 7;
    case hight: return 8;
    case nine: return 9;
    case ten:
    case jack:
    case queen:
    case king: return 10;
    case ace: return 11;
    default:
      assert(false && "should never happen");
      return 0;
    }
};

int main() {
    auto deck{ createDeck() };
    shuffleDeck(deck);
    printDeck(deck);
    return 0;
}