Project:
FizzBuzz++

Description:
An extensible rule-based string transformation ngine applied over integer sequences. Built modular and for scale.

Purpose:
This one-off exercise came about as a simple experiment with ChatGPT. Surprisingly, I had never heard of FizzBuzz until the other day when a co-worker jokingly mentioned it in conversation. Of course, this is generally a very simple problem to approach. I requested for ChatGPT to provide the challenge of solving a more advanced FizzBuzz problem using C++. I also asked it to time my efforts, to which I did not want to exceed 2 hours addressing the problem. The prompt is as follows:

🔧 FizzBuzz++ Challenge
Print numbers from 1 to 100, but:
If divisible by 3 → append "Fizz"
If divisible by 5 → append "Buzz"
If divisible by 7 → append "Bang"
If divisible by 11 → override all previous output and print only "Bong"
If divisible by 13 → insert "Fezz" immediately before the first string that starts with "B" (e.g., before "Buzz", "Bang", or "Bong"). If none, append "Fezz" to the end.
If divisible by 17 → reverse the order of all the output strings (after rules applied)
If none of the conditions apply, print the number.

🧠 Example Outputs:
15 → "FizzBuzz"
33 → "FizzBong" (since divisible by 3 and 11; but 11 overrides)
91 → "Bang" (7 × 13) → "FezzBang" (Fezz inserted before Bang)
255 → divisible by 3, 5, and 17 → original: "FizzBuzz" → reversed: "BuzzFizz"
143 → 11 × 13 → "Bong" overridden by 11, but "Fezz" inserted before "Bong" → "FezzBong"

💡 Requirements:
No hardcoding per-number
Make it scalable/modular for additional rules
Clean string manipulation logic

There were a few small issues in the problem generation. Notably, the example case for the input "33" was incorrect per its own constructed rule-set, which would yield "Bong" instead.