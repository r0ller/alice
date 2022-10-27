const port = browser.runtime.connectNative("com.bitroller.hi_qml");
port.onMessage.addListener(response => {
  // Let's just echo the message back
  port.postMessage("test message");
});
port.postMessage("Hello from WebExtension!");