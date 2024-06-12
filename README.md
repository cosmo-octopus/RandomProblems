<div align="center">
  <h1> Mastering Coding Patterns</h1>
  <i>Coding patterns enhance our ability to map a new problem to an already known problem.<br><br></i>
</div>

```
		⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠐⠉⠁⠀⠉⠉⢻⣶⣤⡀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⢸⣿⡇⠀⣿⣿⡇⣿⣿⡇⣼⣿⣿⣿⣿⣿      
		⠀⠀⠀⠀⠀⠀⢀⢀⠎⠀⠀⢀⣀⣤⣤⣀⣘⣿⣿⣿⣆⠀⠀⠀⠀⠀⠉⠉⣿⣿⠉⠉⢸⣿⡇⠀⣿⣿⡃⣿⣿⡇⣿⣿⡇⠀⣿⣿    ⣿⡇⢴⣿⣿⣿⡆⠀⢸⣿⣿⣿⣿⣿⣿⠀⣿⡇⢸⣿⣿⣿⡇
		⠀⠀⠀⠀⠀⠀⢠⣏⡀⠀⠀⠈⣉⣻⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⢸⣿⣧⣤⣿⣿⡇⣿⣿⡇⠻⣿⣷⣦⡀⠀    ⣿⡇⢸⣿⡀⠛⠃⠀⠀⠀⣿⡇⠀⣿⣿⠀⣿⡇⢸⣿⠀⠀
		⠀⠀⠀⠀⡠⠂⠀⠏⣀⡀⠀⠀⠀⠉⠛⠿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⢸⣿⡟⠛⣿⣿⡇⣿⣿⡇⠀⠈⠻⢿⣿⣦    ⣿⡇⠈⠻⢿⣶⡄⠀⠀⠀⣿⡇⠀⣿⣿⠿⣿⡇⢸⣿⠿⠿⠇
		⠀⠀⠀⣴⣤⣴⠞⢻⣿⠛⢿⣆⠀⠀⣿⣠⣿⣿⣿⣿⣿⠀⠀      ⣿⣿⠀⠀⢸⣿⡇⠀⣿⣿⡇⣿⣿⡇⣿⣿⡇⠀⣿⣿⠀   ⣿⡇⢰⣶⡀⣿⡇⠀⠀⠀⣿⡇⠀⣿⣿⠀⣿⡇⢸⣿⣀⣀⡀
		⠀⠀⠀⣿⣿⠟⠀⡘⠋⠉⣙⣻⣇⠀⢹⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠛⠛⠀⠀⠘⠛⠃⠀⠛⠛⠃⠛⠛⠃⠈⠛⠛⠛⠛⠋⠀   ⠿⠇⠸⠿⠿⠿⠇⠀⠀⠀⠿⠇⠀⠿⠿⠀⠿⠇⠸⠿⠿⠿⠇
		⠀⠀⠀⣿⣡⡄⠚⠻⢿⣿⣿⠿⣿⡆⢻⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀
		⠀⠀⠀⣿⡿⢿⢆⠀⠀⠥⣖⣿⣿⣿⡈⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀               ⣶⣶⡆⠀⣶⣶⠀⢰⣶⣶⠀⢰⣶⣶⡀⢲⣶⣦⠀⢰⣶⣶
		⠀⠀⠤⠁⠤⢤⣦⣶⣿⣿⣿⣿⣿⣿⣷⣬⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀               ⢸⣿⣧⠀⣿⣿⡇⢸⣿⣿⠀⣿⣿⣿⡇⠈⣿⣿⡀⣼⣿⡏
		⠀⠀⠀⠀⠀⠀⠈⠙⠻⡿⢿⣿⠿⠛⢻⠛⢿⣿⣿⣿⣿⣿⡿⠿⠛⠀               ⢸⣿⣿⢸⣿⣿⡇⣼⣿⡇⢸⣿⡿⣿⣧⠀⢻⣿⣇⣿⣿⠁
		⠀⠀⠀⠀⠀⣀⡀⢀⣪⣀⣀⠀⣀⣠⣤⣷⣾⣿⣿⣿⣿⣿⣿⣷⣄⠀               ⠀⣿⣿⢸⣿⣿⣇⣿⣿⠇⢸⣿⡇⣿⣿⡀⠘⣿⣿⣿⡏
		⠀⠀⣐⣋⣿⣿⣿⠿⡿⠁⢠⣾⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷               ⠀⣿⣿⣿⣿⢿⣿⣿⣿⠀⣾⣿⠷⢿⣿⡇⠀⢻⣿⣿⠀⠀
		⣠⣾⣿⣿⣿⠁⠀⢠⠁⢠⠏⣿⡿⠁⣸⡝⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿               ⠀⢸⣿⣿⡏⢸⣿⣿⡿⢰⣿⣿⠀⢸⣿⣷⠀⢸⣿⣿⠀
		                                               ⠀⢸⣿⣿⡇⢸⣿⣿⡇⢸⣿⡇⠀⠀⣿⣿⠀⢸⣿⣿     
```
# Data Structures and Algorithms</h1>

  -   http://www.ideserve.co.in/
  -   https://medium.freecodecamp.org/i-built-an-app-that-makes-learning-algorithms-and-data-structures-way-more-fun-46fbb8afacaf

# Skill Practice

-   https://www.hackerrank.com/
-   https://projecteuler.net/
-   https://leetcode.com/
-   https://codesignal.com/
-   https://coderbyte.com/
-   https://www.codechef.com/
-   https://www.spoj.com/
-   https://www.urionlinejudge.com.br/
-   https://codeforces.com/
-   https://www.interviewbit.com/courses/programming/

# Stanford Online Course

-   http://web.stanford.edu/class/archive/cs/cs161/cs161.1168/
-   http://online.stanford.edu/courses
