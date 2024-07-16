function round(num, to) {
    const mask = Math.pow(10, to);
    var res = Math.round(num * mask);
    return res / mask;
}

function formatMilliseconds(milliseconds) {
    var totalSeconds = Math.floor(milliseconds / 1000);
    var hours = Math.floor(totalSeconds / 3600);
    var minutes = Math.floor((totalSeconds % 3600) / 60);
    var seconds = totalSeconds % 60;

    var formattedTime = '';
    if (hours > 0) {
        formattedTime += hours + ':';
    }
    formattedTime += String(minutes).padStart(2, '0') + ':' + String(seconds).padStart(2, '0');
    return formattedTime;
}

function fitting(videoSize, windowSize) {
    var videoWidth = videoSize.width;
    var videoHeight = videoSize.height;
    var windowWidth = windowSize.width;
    var windowHeight = windowSize.height;

    var videoAspectRatio = videoWidth / videoHeight;
    var windowAspectRatio = windowWidth / windowHeight;

    var fittedWidth, fittedHeight;

    if (videoAspectRatio > windowAspectRatio) {
        fittedWidth = windowWidth;
        fittedHeight = windowWidth / videoAspectRatio;
    } else {
        fittedHeight = windowHeight;
        fittedWidth = windowHeight * videoAspectRatio;
    }

    return Qt.size(fittedWidth, fittedHeight);
}