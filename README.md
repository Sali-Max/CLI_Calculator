# 🔢 CPP CLI Calculator  
A **lightweight and efficient console-based calculator** built using **C++/CLI**.  
It supports **basic arithmetic operations**, **parentheses for complex expressions**, and **string-based input processing**.  


---

## ✨ Features  
✔️ Supports **addition (+), subtraction (-), multiplication (*), and division (/)**  
✔️ Handles **parentheses** for correct **order of operations**  
✔️ Processes **input as a string** for flexibility  

---

## 🚀 How to Use  
1️⃣ **Clone the Repository** 🔹  
```bash
git clone https://github.com/Sali-Max/CPP_CLI_Calculator.git
cd CPP_CLI_Calculator
```
2️⃣ **Compile the Code** ⚙️  
```bash
g++ main.cpp -o calculator
```
3️⃣ **Run the Program** ▶️  
```bash
./calculator
```

📌 **[Download Precompiled Versions Here](https://github.com/Sali-Max/CPP_CLI_Calculator/releases)** (if available).  

---

## ⚠️ Known Issues & Workaround  
🔸 Due to **time constraints**, some bugs have not been fixed.  
🔸 If a number appears **after** a closing parenthesis without an operator, it is incorrectly multiplied.  
   - Example: `(2*2)2` → ❌ Incorrect  
🔸 If a number appears **before** an opening parenthesis without an operator, it is correctly multiplied.  
   - Example: `2(2*2)` → ✅ Correct  

**🛠 Workaround**  
➡ **Always include an operator after a closing parenthesis** to avoid errors.  

---

## 🤝 Contributing  
We welcome contributions! If you’d like to improve this project, feel free to:  
- Fork the repository  
- Submit pull requests  
- Report issues  

📩 **Have suggestions?** Open an [Issue](https://github.com/Sali-Max/CPP_CLI_Calculator/issues).  

---

## 📜 License  
This project is licensed under the [MIT License](LICENSE).  

📌 **Created by [Sali-Max](https://github.com/Sali-Max)**  
