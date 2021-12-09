#include "WordCount.c"

#include <gtest/gtest.h>

TEST(WordCountTest, NoText) {
    FILE* in = fopen("some_name.txt", "w+");
    int res[3];
    
    solve(in, res);
    ASSERT_EQ(res[0], 0) << "Wrong number of bytes NoText";
    ASSERT_EQ(res[1], 0) << "Wrong number of lines NoText";
    ASSERT_EQ(res[2], 0) << "Wrong number of words NoText";

    fclose(in);
    remove("some_name.txt");
}

TEST(WordCountTest, OneLine) {
    FILE* in = fopen("some_name.txt", "w+");
    fprintf(in, "This is the first line\n");
    rewind(in);
    int res[3];
    
    solve(in, res);
    ASSERT_EQ(res[0], 23) << "Wrong number of bytes OneLine";
    ASSERT_EQ(res[1], 1) << "Wrong number of lines OneLine";
    ASSERT_EQ(res[2], 5) << "Wrong number of words OneLine";

    fclose(in);
    remove("some_name.txt");
}

TEST(WordCountTest, MultiLine) {
    FILE* in = fopen("some_name.txt", "w+");
    char contents[] = 
        "Some Line\n"
        "Another line\n"
        "There are many variations of passages of Lorem Ipsum available, "
        "but the majority have suffered alteration in some form, by injected humour, "
        "or randomised words which don't look even slightly believable. \n"
        "If you are going to use a passage of Lorem Ipsum, you need to be sure "
        "there isn't anything embarrassing hidden in the middle of text";
    fprintf(in, contents);
    rewind(in);
    int res[3];
    
    solve(in, res);
    ASSERT_EQ(res[0], 359) << "Wrong number of bytes MultiLine";
    ASSERT_EQ(res[1], 4) << "Wrong number of lines MultiLine";
    ASSERT_EQ(res[2], 61) << "Wrong number of words MultiLine";

    fclose(in);
    remove("some_name.txt");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}