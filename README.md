<h2>FizzBuzz++</h2>
<b>Description:</b><br>
An extensible rule-based string transformation ngine applied over integer sequences. Built modular and for scale.<br>
<br>
<b>Purpose:</b><br>
This one-off exercise came about as a simple experiment with ChatGPT. Surprisingly, I had never heard of FizzBuzz until the other day when a co-worker jokingly mentioned it in conversation. Of course, this is generally a very simple problem to approach. I requested for ChatGPT to provide the challenge of solving a more advanced FizzBuzz problem using C++. I also asked it to time my efforts, to which I did not want to exceed 2 hours addressing the problem. The prompt is as follows:<br>
<br>
🔧 <b>FizzBuzz++ Challenge</b><br>
Print numbers from 1 to 100, but:<br>
If divisible by 3 → append "Fizz".<br>
If divisible by 5 → append "Buzz".<br>
If divisible by 7 → append "Bang".<br>
If divisible by 11 → override all previous output and print only "Bong".<br>
If divisible by 13 → insert "Fezz" immediately before the first string that starts with "B" (e.g., before "Buzz", "Bang", or "Bong"). If none, append "Fezz" to the end.<br>
If divisible by 17 → reverse the order of all the output strings (after rules applied).<br>
If none of the conditions apply, print the number.<br>
<br>
🧠 <b>Example Outputs:</b><br>
15 → "FizzBuzz"<br>
33 → "FizzBong" (since divisible by 3 and 11; but 11 overrides).<br>
91 → "Bang" (7 × 13) → "FezzBang" (Fezz inserted before Bang).<br>
255 → divisible by 3, 5, and 17 → original: "FizzBuzz" → reversed: "BuzzFizz".<br>
143 → 11 × 13 → "Bong" overridden by 11, but "Fezz" inserted before "Bong" → "FezzBong".<br>
<br>
💡 <b>Requirements:</b><br>
No hardcoding per-number.<br>
Make it scalable/modular for additional rules.<br>
Clean string manipulation logic.<br>
<br>
<i>There were a few small issues in the problem generation. Notably, the example case for the input "33" was incorrect per its own constructed rule-set, which would yield "Bong" instead.</i>