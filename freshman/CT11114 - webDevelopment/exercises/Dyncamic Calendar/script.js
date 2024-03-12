function isLeapYear(year) {
  return (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0;
}
function numberOfDaysInMonth(year, month) {
  if (month === 2) {
    return isLeapYear(year) ? 29 : 28;
  }
  if ([4, 6, 9, 11].includes(month)) {
    return 30;
  }
  return 31;
}
function firstDayOfMonth(year, month) {
  // Formula to calculate the day of the week for the first day of the month
  // Zeller's Congruence algorithm
  // Adjust month and year for Zeller's Congruence algorithm
  if (month < 3) {
    month += 12;
    year -= 1;
  }

  // Zeller's Congruence algorithm
  const q = 1; // Day of the month (1 for the first day)
  const m = month;
  const K = year % 100; // Year of the century
  const J = Math.floor(year / 100); // Zero-based century
  const h =
    (q +
      Math.floor((13 * (m + 1)) / 5) +
      K +
      Math.floor(K / 4) +
      Math.floor(J / 4) -
      2 * J) %
    7;

  // Convert the result to match the desired day of the week numbering
  let dayOfWeek = (h + 6) % 7; // Convert to Sunday as 0, Saturday as 6

  return dayOfWeek;
}

function generateCalendar() {
  const year = parseInt(document.getElementById("year").value);
  const month = parseInt(document.getElementById("month").value);

  if (isNaN(month) || month < 1 || month > 12) {
    alert("Please enter a valid month");
  } else if (isNaN(year) || year < 1 || year > 9999) {
    alert("Please enter a valid year");
  } else {
    const daysInMonth = numberOfDaysInMonth(year, month);
    let firstDay = firstDayOfMonth(year, month);
    let calendarHTML = "<table>";
    calendarHTML +=
      "<tr><th>Sun</th><th>Mon</th><th>Tue</th><th>Wed</th><th>Thu</th><th>Fri</th><th>Sat</th></tr>";

    let currentDay = 1;
    for (let i = 0; i < 6; i++) {
      calendarHTML += "<tr>";
      for (let j = 0; j < 7; j++) {
        if (i === 0 && j < firstDay) {
          calendarHTML += "<td></td>";
        } else if (currentDay > daysInMonth) {
          calendarHTML += "<td></td>";
        } else {
          calendarHTML += `<td class="number">${currentDay}</td>`;
          currentDay++;
        }
      }
      calendarHTML += "</tr>";
      if (currentDay > daysInMonth) {
        break;
      }
    }
    calendarHTML += "</table>";
    document.getElementById("calendarContainer").innerHTML = calendarHTML;
  }
}
