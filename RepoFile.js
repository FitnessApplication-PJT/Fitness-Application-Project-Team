let video;
let poseNet;
let poses = [];
let currentModel;
let currentPostureIndex = 0;
const postureLabels = ["PostureA", "PostureB", "PostureC", "PostureD", "PostureE"];
let poseLabel = "";
let poseTimer = 300;
const poseTimerThreshold = 300;
const posesPerStep = 2;
let stepsCompleted = 0;
const totalSteps = 3;

function setup() {
    createCanvas(640, 480);
    video = createCapture(VIDEO);
    video.hide();


    currentModel = ml5.neuralNetwork();
    loadModel(currentModel, "modelAB");


    poseNet = ml5.poseNet(video, modelReady);
    poseNet.on('pose', function(results) {
        poses = results.length;
    });
}

function modelReady() {
    console.log('PoseNet model is ready!');
}


function loadModel(model, folderName) {
    const modelInfo = {
        model: `${folderName}/model.json`,
        metadata: `${folderName}/model_meta.json`,
        weights: `${folderName}/model.weights.bin`,
    };
    model.neuralNetwork.load(modelInfo, function() {
        console.log(`${folderName} Model loaded successfully!`);
    });
}

function draw() {
    image(video, 0, 0, width, height);


    drawPose();


    classifyPose();


    fill(255);
    textSize(24);
    textAlign(CENTER, TOP);
    text(`Current Pose: ${poseLabel}`, width / 2, 10);
    text(`Pose Timer: ${poseTimer}`, width / 2, 50);
}


function drawPose() {
    for (let i = 0; i < poses.length; i++) {
        let pose = poses[i].pose;
        for (let j = 0; j < pose.keypoints.length; j++) {
            let keypoint = pose.keypoints[j];
            fill(255, 0, 0);
            ellipse(keypoint.position.x, keypoint.position.y, 10, 10);
        }
    }
}


function classifyPose() {
    if (poses.length > 0) {
        let inputs = [];
        let pose = poses[0].pose; // Assuming the first detected pose
        for (let i = 0; i < pose.keypoints.length; i++) {
            let x = pose.keypoints[i].position.x;
            let y = pose.keypoints[i].position.y;
            inputs.push(x);
            inputs.push(y);
        }

        currentModel.classify(inputs, gotResult);
    } else {
        setTimeout(classifyPose, 100);
    }
}


function gotResult(error, results) {
    if (results[0].confidence > 0.75) {
        poseLabel = results[0].label.toUpperCase();
        if (poseLabel === postureLabels[currentPostureIndex]) {
            console.log(`Correct Pose: ${poseLabel}`);

            if (poseTimer > 0) {
                poseTimer--;
            }
            // Check if the timer has reached 0
            if (poseTimer === 0) {

                currentPostureIndex++;
                if (currentPostureIndex < postureLabels.length) {
                    console.log(`Switching to ${postureLabels[currentPostureIndex]}`);

                    poseTimer = poseTimerThreshold;

                    if (currentPostureIndex === posesPerStep) {
                        stepsCompleted++;
                        console.log(`Step ${stepsCompleted} completed`);
                        if (stepsCompleted < totalSteps) {

                            currentModel = ml5.neuralNetwork();
                            loadModel(currentModel, `newModelForStep${stepsCompleted}`);
                            currentPostureIndex = 0;
                        } else {
                            // Alert when all postures are completed
                            alert("All postures completed!");
                            noLoop();
                            return;
                        }
                    }
                }
            }
        }
    }
    classifyPose();
}


function checkPosture() {

}
