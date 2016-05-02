/*
 * +===============================================
 * | Author:        Parham Alvani (parham.alvani@gmail.com)
 * |
 * | Creation Date: 02-05-2016
 * |
 * | File Name:     index.js
 * +===============================================
 */
function onDocumentLoad() {
    document.getElementById("inJS").onclick = inJS;
}

function inHTML() {
    alert(this);
}

function inJS() {
    alert(this);
}

window.onload = onDocumentLoad;
