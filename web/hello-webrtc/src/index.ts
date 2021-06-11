async function onInit() {
  await loadDevices();

  try {
    const stream = await navigator.mediaDevices.getUserMedia({
      video: true,
      audio: true,
    });
    const el = document.querySelector("video");
    el.srcObject = stream;
  } catch (err) {
    console.log(`cannot get the user media: ${err}`);
  }
}

async function loadDevices() {
  const devices = await navigator.mediaDevices.enumerateDevices();
  const el = document.getElementById("devices");

  for (const device of devices) {
    const li = document.createElement("li");
    li.innerHTML = `<i>${device.label}</i> [${device.deviceId}]`;

    el.appendChild(li);
  }
}

onInit();
