//
//  Chatbot.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include "Chatbot.hpp"

Chatbot::Chatbot(const std::string filename){
    Loader loader;

    m_conversations = loader.getConversations(filename);
}

void Chatbot::printIntroduction() const {
    std::cout << "Vitejte v chatbotovi. Muzete se me ptat na otazky a ja budu odpovidat." << std::endl;
}

bool isRunning = true;
void Chatbot::chat() const {
    std::string userSentence = "";
    std::string computerAnswer = "";

    printIntroduction();

    while (isRunning) {
        userSentence = getUserSentence();
        if (userSentence != "konec") {
            computerAnswer = findAnswer(userSentence);
            printAnswer(computerAnswer);
        } else {
            isRunning = false;
        }
    }
}

std::string Chatbot::getUserSentence() const{
    std::string sentence = "";
    std::cout << "Zadej vetu: ";
    getline(std::cin, sentence);
    return sentence;
}

std::string Chatbot::findAnswer(const std::string userSentence) const {
    for(auto conversation: m_conversations) {
        if (conversation.matches(userSentence)) {
            return conversation.response;
        }
    }

    return "";
}

void Chatbot::printAnswer(const std::string computerAnswer) const {
    if (!computerAnswer.empty()) {
        std::cout << "Odpoved pocitace je: " << computerAnswer << std::endl;
    } else {
        std::cout << "Nerozumim otazce. Zeptej se prosim jinak." << std::endl;
    }
}
