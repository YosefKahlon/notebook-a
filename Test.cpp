/**
 *
 *
 * AUTHORS: <Yosef Or Kahlon>
 *
 * Date: 2022 - 3
 */

#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"

using namespace ariel;

#include <string>
#include <algorithm>

using namespace std;


//        test.write(1, 1, 1, Direction::Horizontal, "Y");
//        CHECK_THROWS(test.write(1, 1, 1, Direction::Horizontal, "d"));


TEST_CASE (" -- Negative input -- ") {

    Notebook test;
//////////////////////////////////////////////////////////////////////
            SUBCASE("-------------write------------") {
        //negative page
                CHECK_THROWS(test.write(-1, 1, 3, Direction::Horizontal, "d"));
                CHECK_THROWS(test.write(-1, 1, 3, Direction::Vertical, "d"));


        //negative row
                CHECK_THROWS(test.write(1, -1, 3, Direction::Horizontal, "d"));
                CHECK_THROWS(test.write(1, -1, 3, Direction::Vertical, "d"));


        //negative col
                CHECK_THROWS(test.write(1, 1, -3, Direction::Horizontal, "d"));
                CHECK_THROWS(test.write(1, 1, -3, Direction::Vertical, "d"));
    }
//////////////////////////////////////////////////////////////////////
            SUBCASE("-------------read------------") {
        //negative page
                CHECK_THROWS(test.read(-1, 1, 3, Direction::Horizontal, 1));
                CHECK_THROWS(test.read(-1, 1, 3, Direction::Vertical, 1));


        //negative row
                CHECK_THROWS(test.read(1, -1, 3, Direction::Horizontal, 1));
                CHECK_THROWS(test.read(1, -1, 3, Direction::Vertical, 1));


        //negative col
                CHECK_THROWS(test.read(1, 1, -3, Direction::Horizontal, 1));
                CHECK_THROWS(test.read(1, 1, -3, Direction::Vertical, 1));


        //negative length to read
                CHECK_THROWS(test.read(1, 1, 3, Direction::Vertical, -1));
    }
//////////////////////////////////////////////////////////////////////

            SUBCASE("-------------erase------------") {
        //negative page
                CHECK_THROWS(test.erase(-1, 1, 3, Direction::Horizontal, 1));
                CHECK_THROWS(test.erase(-1, 1, 3, Direction::Vertical, 1));

        //negative row
                CHECK_THROWS(test.erase(1, -1, 3, Direction::Horizontal, 1));
                CHECK_THROWS(test.erase(1, -1, 3, Direction::Vertical, 1));


        //negative col
                CHECK_THROWS(test.erase(1, 1, -3, Direction::Horizontal, 1));
                CHECK_THROWS(test.read(1, 1, -3, Direction::Vertical, 1));

        //negative length to read
                CHECK_THROWS(test.erase(1, 1, 3, Direction::Vertical, -2));
                CHECK_THROWS(test.erase(1, 1, 3, Direction::Horizontal, -6));
    }

}
TEST_CASE("2"){
    Notebook test;
    CHECK_THROWS(test.read(1, 1, 3, Direction::Vertical, 102));
    CHECK_THROWS(test.read(1, 1, 3, Direction::Horizontal, 102));
    CHECK_THROWS(test.erase(1, 1, 3, Direction::Horizontal, 102));

    CHECK_THROWS(test.write(1, 1, 102, Direction::Horizontal, "sss"));
    CHECK_THROWS(test.write(1, 1, 102, Direction::Vertical, "sss"));


    CHECK_THROWS(test.read(1, 1, 102, Direction::Vertical, 1));
    CHECK_THROWS(test.read(1, 1, 102, Direction::Horizontal, 1));

    CHECK_THROWS(test.erase(1, 1, 102, Direction::Horizontal, 2));
    CHECK_THROWS(test.erase(1, 1, 102, Direction::Horizontal, 2));




}




