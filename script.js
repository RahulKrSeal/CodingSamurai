document.addEventListener("DOMContentLoaded", function() {
    const display = document.getElementById("display");
    const buttons = document.querySelectorAll(".button");
  
    let currentInput = "";
  
    buttons.forEach(button => {
      button.addEventListener("click", function() {
        const value = this.getAttribute("data-value");
  
        if (value === "clear") {
          currentInput = "";
        } else if (value === "backspace") {
          currentInput = currentInput.slice(0, -1);
        } else if (value === "=") {
          try {
            currentInput = eval(currentInput).toString();
          } catch (error) {
            currentInput = "Error";
          }
        } else {
          currentInput += value;
        }
  
        display.value = currentInput;
      });
    });
  });
  