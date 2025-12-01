# MAJOR-C-PROJECT
1. Project Overview
- Create a console-based quiz game inspired by KBC.
- Player answers multiple-choice questions (MCQs).
- Two lifelines available:
- 50-50 → Removes two wrong options.
- Skip Question → Skips the current question without penalty.

2. Core Features
- Question Bank:
- Store questions, 4 options, and the correct answer.
- Use arrays, structures, or files for storage.
- Game Flow:
- Display question + options.
- Accept player’s choice.
- Check correctness and update score.
- Lifelines:
- Track usage (each lifeline can be used only once).
- Implement logic for 50-50 and skip.
- Scoring System:
- Increment score for correct answers.
- No negative marking for wrong answers (optional).
- Winning Condition:
- End after all questions or when player quits.
- Display final score.

3. Technical Requirements
- Language: C (ANSI C standard).
- Data Structures:
- struct Question { char text[200]; char options[4][100]; int correctOption; };
- Array of struct Question for multiple questions.
- Functions:
- void displayQuestion(struct Question q);
- int useFiftyFifty(struct Question q);
- void skipQuestion();
- int checkAnswer(struct Question q, int choice);
- - Control Flow:
- Use loops for multiple questions.
- Use switch or if-else for lifeline handling.

4. Step-by-Step Implementation
- Initialize Question Bank (hardcoded or file input).
- Display Welcome Screen (rules, lifelines).
- Loop Through Questions:
- Show question + options.
- Ask if lifeline is needed.
- Take answer input.
- Check correctness.
- Update score.
 
5. Handle Lifelines:
- If 50-50 → randomly remove 2 wrong options.
- If Skip → move to next question.

 
6. End Game:
- Show final score.
- Optionally display correct answers for review.


