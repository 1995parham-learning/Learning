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

    var i, j, tr, td, tdInput, label;

    label = document.createElement("label");
    label.innerHTML = "A:";
    document.getElementById("matrix").appendChild(label);
    var table1 = document.createElement("table");
    for (i = 0; i < n; i++) {
        tr = document.createElement("tr");
        for (j = 0; j < m; j++) {
            td = document.createElement("td");
            tdInput = document.createElement("input");
            tdInput.id = "table1Input" + i + j;
            td.appendChild(tdInput);
            tr.appendChild(td);
        }
        table1.appendChild(tr);
    }
    document.getElementById("matrix").appendChild(table1);

    label = document.createElement("label");
    label.innerHTML = "B:";
    document.getElementById("matrix").appendChild(label);
    var table2 = document.createElement("table");
    for (i = 0; i < m; i++) {
        tr = document.createElement("tr");
        for (j = 0; j < k; j++) {
            td = document.createElement("td");
            tdInput = document.createElement("input");
            tdInput.id = "table2Input" + i + j;
            td.appendChild(tdInput);
            tr.appendChild(td);
        }
        table2.appendChild(tr);
    }
    document.getElementById("matrix").appendChild(table2);


    label = document.createElement("label");
    label.innerHTML = "C:";
    document.getElementById("matrix").appendChild(label);
    var table3 = document.createElement("table");
    for (i = 0; i < n; i++) {
        tr = document.createElement("tr");
        for (j = 0; j < k; j++) {
            td = document.createElement("td");
            tdInput = document.createElement("input");
            tdInput.id = "table3Input" + i + j;
            tdInput.onclick = function (r, c, m) {
                return function () {
                    var result = 0;
                    var i;
                    for (i = 0; i < m; i++) {
                        var v1 = parseInt(document.getElementById("table1Input" + r + i).value);
                        var v2 = parseInt(document.getElementById("table2Input" + i + c).value);
                        result = result + v1 * v2;
                    }
                    document.getElementById("table3Input" + r + c).value = result;
                };
            }(i, j, m);
            td.appendChild(tdInput);
            tr.appendChild(td);
        }
        table3.appendChild(tr);
    }
    document.getElementById("matrix").appendChild(table3);
}