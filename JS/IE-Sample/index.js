/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 01-05-2016
 * |
 * | File Name:     index.js
 * +===============================================
 */
function createMatrixInput() {
    var n = parseInt(document.getElementById("inputN").value);
    var m = parseInt(document.getElementById("inputM").value);
    var k = parseInt(document.getElementById("inputK").value);

    var table1 = document.createElement("table");
    for (var i = 0; i < n; i++) {
        var tr = document.createElement("tr");
        for (var j = 0; j < m; j++) {
            var td = document.createElement("td");
            var tdInput = document.createElement("input");
            tdInput.id = "table2Input" + i + j;
            td.appendChild(tdInput);
            tr.appendChild(td);
        }
        table1.appendChild(tr);
    }
    document.getElementById("matrix").appendChild(table1);

    var table2 = document.createElement("table");
    for (var i = 0; i < m; i++) {
        var tr = document.createElement("tr");
        for (var j = 0; j < k; j++) {
            var td = document.createElement("td");
            var tdInput = document.createElement("input");
            tdInput.id = "table2Input" + i + j;
            td.appendChild(tdInput);
            tr.appendChild(td);
        }
        table2.appendChild(tr);
    }
    document.getElementById("matrix").appendChild(table2);
}