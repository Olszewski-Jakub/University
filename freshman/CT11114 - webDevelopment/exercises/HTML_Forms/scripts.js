function removeInvisibleChars(str) {
  return str.replace(/\s/g, "");
}
function displayError(errorElement, errorMessage) {
  if (errorMessage) {
    errorElement.textContent = errorMessage;
    errorElement.classList.add("error");
  } else {
    errorElement.textContent = "";
    errorElement.classList.remove("error");
  }
}
function validateForm(object) {
  var isValid = true;

  var categoryError = document.getElementById("categoryError");
  var questionError = document.getElementById("questionError");
  var nameError = document.getElementById("nameError");

  if (object.question_category == 0) {
    displayError(categoryError, "Please select a category");

    isValid = false;
  } else {
    displayError(categoryError, "");
  }

  if (removeInvisibleChars(object.question).length < 2) {
    displayError(questionError, "Please enter a question");

    isValid = false;
  } else {
    displayError(questionError, "");
  }

  if (removeInvisibleChars(object.name) == "") {
    displayError(nameError, "Please enter your name");

    isValid = false;
  } else {
    displayError(nameError, "");
  }
  var emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
  if (
    removeInvisibleChars(object.email) == "" ||
    !emailRegex.test(object.email)
  ) {
    displayError(emailError, "Please enter a valid email address");

    isValid = false;
  } else {
    displayError(emailError, "");
  }

  return isValid;
}

function submitForm() {
  var form = document.getElementById("myForm");
  event.preventDefault();
  var formData = new FormData(form);
  var object = {};
  formData.forEach(function (value, key) {
    object[key] = value;
  });
  if (validateForm(object)) {
    alert("Form submitted successfully!");
    form.reset();
  }
}
