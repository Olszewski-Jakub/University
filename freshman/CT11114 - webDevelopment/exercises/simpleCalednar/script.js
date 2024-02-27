function generateCalendar() {
  const daysInMonth = parseInt(document.getElementById("days").value);
  const startDay = parseInt(document.getElementById("startDay").value);

  if (daysInMonth < 28 || daysInMonth > 31 || isNaN(daysInMonth)) {
    alert("Please enter a valid number of days in month");
  } else if (startDay < 0 || startDay > 6 || isNaN(startDay)) {
    alert("Please enter a valid start day");
  } else {
    let calendarHTML = "<table>";
    calendarHTML +=
      "<tr><th>Sun</th><th>Mon</th><th>Tue</th><th>Wed</th><th>Thu</th><th>Fri</th><th>Sat</th></tr>";

    let currentDay = 1;
    for (let i = 0; i < 6; i++) {
      calendarHTML += "<tr>";
      for (let j = 0; j < 7; j++) {
        if ((i === 0 && j < startDay) || currentDay > daysInMonth) {
          calendarHTML += "<td></td>";
        } else {
          if (currentDay === new Date().getDate()) {
            calendarHTML += `<td class="current-day">${currentDay}</td>`;
          } else {
            calendarHTML += `<td class="number">${currentDay}</td>`;
          }
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
