#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class to store each question
class Question {
public:
    string questionText;
    string options[4];
    int correctOption;

    // Constructor to initialize question and options
    Question(string q, string o1, string o2, string o3, string o4, int correct) {
        questionText = q;
        options[0] = o1;
        options[1] = o2;
        options[2] = o3;
        options[3] = o4;
        correctOption = correct;
    }

    // Method to display question and options
    void displayQuestion() {
        cout << questionText << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    // Method to check if answer is correct
    bool checkAnswer(int answer) {
        return answer == correctOption;
    }
};

// Class to manage the quiz logic
class Quiz {
private:
    vector<Question> questions;
    int score = 0;

public:
    // Add a question to the quiz
    void addQuestion(Question q) {
        questions.push_back(q);
    }

    // Start the quiz
    void startQuiz() {
        int answer;
        for (int i = 0; i < questions.size(); i++) {
            questions[i].displayQuestion();
            cout << "Your answer (1-4): ";
            cin >> answer;
            if (questions[i].checkAnswer(answer)) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Incorrect!" << endl;
            }
            cout << endl;
        }
        cout << "Quiz Finished! Your score is: " << score << "/" << questions.size() << endl;
    }
};

// Main function
int main() {
    Quiz quiz;
    quiz.addQuestion(Question("What is 2 + 2?", "1", "2", "3", "4", 4));
    quiz.addQuestion(Question("Which planet is known as the Red Planet?", "Earth", "Mars", "Jupiter", "Saturn", 2));
    quiz.startQuiz();

    return 0;
}