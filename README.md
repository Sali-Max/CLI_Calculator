**CPP_CLI_Calculator**
CPP_CLI_Calculator is a simple console-based calculator built using C++/CLI.  
It supports basic arithmetic operations and parentheses for complex expressions.  


**Features**  
✔️ Supports addition (+), subtraction (-), multiplication (*), and division (/)  
✔️ Handles parentheses for order of operations  
✔️ Processes input as a string  




**🚀 How to Use**

1️⃣ Clone Project 🔹
```bash
git clone https://github.com/YourUsername/CPP_CLI_Calculator.git
cd CPP_CLI_Calculator
```
2️⃣ Compile ⚙️
```bash
g++ main.cpp
```
3️⃣ Run ▶️
```bash
./a.out
```



**⚠️ Known Bug**
🔸 Due to **time constraints**, some bugs in the program have not been fixed.  
🔸 If a number appears **after** a closing parenthesis without an operator, it is incorrectly multiplied.  
   Example: `(2*2)2` → ❌ Incorrect  
🔸 If a number appears **before** an opening parenthesis without an operator, it is correctly multiplied.  
   Example: `2(2*2)` → ✅ Correct  

**🛠 Workaround**
➡ **Always include an operator after a closing parenthesis** to avoid errors.
