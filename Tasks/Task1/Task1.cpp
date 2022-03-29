
void task1() {
    std::string searchWord = "one";
    std::string currentWord;
    int amountOfMeets = 0;
    std::ifstream words;
    words.open("E:\\HomeWorks\\ifstream\\Tasks\\Task1\\words.txt");

    while (!words.eof()) {
        words >> currentWord;
        if (currentWord == searchWord)
            amountOfMeets++;
    }
    std::cout << amountOfMeets << std::endl;

    words.close();
}
