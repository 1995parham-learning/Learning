async function onInit() {
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

onInit();
