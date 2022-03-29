
void fill_questions_vectors(std::vector<std::string> &v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = "E:\\HomeWorks\\ifstream\\Tasks\\WhatWhereWhen\\Questions\\q" + std::to_string(i + 1) + ".txt";
    }
}

void fill_answers_vector(std::vector<std::string> &v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = "E:\\HomeWorks\\ifstream\\Tasks\\WhatWhereWhen\\Answers\\a" + std::to_string(i + 1) + ".txt";
    }
}

std::string get_text_from_file(std::ifstream &ifs) {
    std::stringstream ss;

    while (!ifs.eof()) {
        std::string buf;
        ifs >> buf;
        ifs.rdstate() == std::ios_base::eofbit ?
        ss << buf :
        ss << buf << " ";
    }

    return ss.str();
}

std::string get_question_or_answer(std::string path) {
    std::ifstream ifs(path);
    while (!ifs.is_open()) {
        std::cout << "Wrong path. Try again:" << std::endl;
        std::cin >> path;
    }
    std::string text = get_text_from_file(ifs);
    ifs.close();
    return text;
}

int www() {
    std::vector<std::string> questions(13);
    std::vector<std::string> answers(13);
    std::vector<bool> states(13, 1);

    fill_questions_vectors(questions);
    fill_answers_vector(answers);

    int offset = 0, sector = -1, round = 1;
    int connoisseurs = 0, spectators = 0;
    while (connoisseurs != 6 && spectators != 6) {
        std::cout << "The " << round << " Round" << std::endl << "BOOOOOOOOOOOOOM" << std::endl;
        std::cout << "Score: " << std::endl << "Connoisseurs: " << connoisseurs << " - Spectators: " << spectators << std::endl;
        std::cout << "Enter offset:" << std::endl;
        std::cin >> offset;
        sector += offset;
        sector %= 13;

        while (!states[sector]) {
            sector++;
            sector %= 13;
        }


        std::cout << "The " << sector + 1 << " Sector" << std::endl << "Question:" << std::endl;
        std::cout << get_question_or_answer(questions[sector]) << std::endl;
        std::cout << "Your answer:" << std::endl;
        std::string playerAnswer;
        std::cin >> playerAnswer;
        std::string trueAnswer = get_question_or_answer(answers[sector]);
        if (playerAnswer == trueAnswer) {
            connoisseurs++;
            std::cout << "It is correct answer! Connoisseurs won in this round!" << std::endl;
        } else {
            spectators++;
            std::cout << "Sorry, it is incorrect answer! Spectators won in this round!" << std::endl;
        }
        states[sector] = 0;
        round++;
    }
    if (spectators == 6)
        std::cout << "Spectators won" << std::endl;
    else
        std::cout << "Connoisseurs won" << std::endl;
}
