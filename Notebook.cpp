//
// Created by 97252 on 3/22/2022.
//

#include "Notebook.hpp"
#include "iostream"
#include "string"
#include "stdexcept"

using namespace std;
using namespace ariel;


bool negative_num(int num) {

    if (num < 0) {
        return true;
    } else {
        return false;
    }
}
bool invalid_num(int num){
    if (num > 100) {
        return true;
    } else {
        return false;
    }
}


void Notebook::write(int page, int row, int column, Direction direction, const std::string &text) {


    int len = text.length();
    if (!Notebook::read(page, row, column, direction, len).empty()) {
        throw std::invalid_argument("You can't write there !!");
    }

    if (negative_num(page)) {
        throw std::invalid_argument("Page number start from 0 !!");
    }
    if (negative_num(row)) {
        throw std::invalid_argument("Row number start from 0 !!");
    }
    if (negative_num(column)) {
        throw std::invalid_argument("Column number start from 0 !!");
    }
    if (invalid_num(column)){
        throw std::invalid_argument("There are only 100 columns!!");
    }


    cout << text << endl;
}


std::string
Notebook::read(int page, int row, int column, Direction direction, int length) {


    if (negative_num(page)) {
        throw std::invalid_argument("Page number start from 0 !!");
    }
    if (negative_num(row)) {
        throw std::invalid_argument("Row number start from 0 !!");
    }
    if (negative_num(column)) {
        throw std::invalid_argument("Column number start from 0 !!");
    }

    if (negative_num(length)) {
        throw std::invalid_argument("Negative length to reading !!");
    }

    if (invalid_num(column)){
        throw std::invalid_argument("There are only 100 columns!!");
    }


    return " you are right !";

}

void
Notebook::erase(int page, int row, int column, Direction direction, int length) {
    if (negative_num(page)) {
        throw std::invalid_argument("Page number start from 0 !!");
    }
    if (negative_num(row)) {
        throw std::invalid_argument("Row number start from 0 !!");
    }
    if (negative_num(column)) {
        throw std::invalid_argument("Column number start from 0 !!");
    }
    if (negative_num(length)) {
        throw std::invalid_argument("Negative length for erasure !!");
    }
    if (invalid_num(column) || invalid_num(length)){
        throw std::invalid_argument("No more than 100!!");
    }

}

void Notebook::show(int page_number) {
    cout << page_number << endl;


}


