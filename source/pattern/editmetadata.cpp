#include "editmetadata.h"
#include "ui_editmetadata.h"
#include "QMessageBox"

EditMetadata::EditMetadata(QWidget *parent, Database* db) :
    QDialog(parent),
    ui(new Ui::EditMetadata)
{
    this->db=db;
    ui->setupUi(this);
}

EditMetadata::~EditMetadata()
{
    delete ui;
}

//Disables all the edit ui buttons
void EditMetadata::disableAll(){
    ui->btnEditDatabaseName->setEnabled(false);
    ui->btnEditRef1->setEnabled(false);
    ui->btnEditRef2->setEnabled(false);
    ui->btnEditRef3->setEnabled(false);
    ui->btnEditNumKeyPoints->setEnabled(false);
    ui->btnEditWarpSize->setEnabled(false);
    ui->btnEditRelKeyDistance->setEnabled(false);
    ui->btnEditRedWeight->setEnabled(false);
    ui->btnEditGreenWeight->setEnabled(false);
    ui->btnEditBlueWeight->setEnabled(false);
    ui->btnEditMaxDistance->setEnabled(false);
    ui->btnEditMinDistance->setEnabled(false);
    ui->btnEditMinRatio->setEnabled(false);

    ui->btnHelpNumKeyPoints->setEnabled(false);
    ui->btnHelpWarpSize->setEnabled(false);
    ui->btnHelpRelKeyDistance->setEnabled(false);
    ui->btnHelpRedWeight->setEnabled(false);
    ui->btnHelpGreenWeight->setEnabled(false);
    ui->btnHelpBlueWeight->setEnabled(false);
    ui->btnHelpMaxDistance->setEnabled(false);
    ui->btnHelpMinDistance->setEnabled(false);
    ui->btnHelpMinRatio->setEnabled(false);

    ui->btnSave->setEnabled(false);
    ui->btnAddMetadataElement->setEnabled(false);

}
//Enables all the ui buttons
void EditMetadata::enableAll(){
    ui->btnEditDatabaseName->setEnabled(true);
    ui->btnEditRef1->setEnabled(true);
    ui->btnEditRef2->setEnabled(true);
    ui->btnEditRef3->setEnabled(true);
    ui->btnEditNumKeyPoints->setEnabled(true);
    ui->btnEditWarpSize->setEnabled(true);
    ui->btnEditRelKeyDistance->setEnabled(true);
    ui->btnEditRedWeight->setEnabled(true);
    ui->btnEditGreenWeight->setEnabled(true);
    ui->btnEditBlueWeight->setEnabled(true);
    ui->btnEditMaxDistance->setEnabled(true);
    ui->btnEditMinDistance->setEnabled(true);
    ui->btnEditMinRatio->setEnabled(true);

    ui->btnHelpNumKeyPoints->setEnabled(true);
    ui->btnHelpWarpSize->setEnabled(true);
    ui->btnHelpRelKeyDistance->setEnabled(true);
    ui->btnHelpRedWeight->setEnabled(true);
    ui->btnHelpGreenWeight->setEnabled(true);
    ui->btnHelpBlueWeight->setEnabled(true);
    ui->btnHelpMaxDistance->setEnabled(true);
    ui->btnHelpMinDistance->setEnabled(true);
    ui->btnHelpMinRatio->setEnabled(true);

    ui->btnSave->setEnabled(true);
    ui->btnAddMetadataElement->setEnabled(true);
}

void EditMetadata::on_btnEditDatabaseName_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditDatabaseName->setEnabled(true);ui->txtDatabaseName->setEnabled(true);}
    else{enableAll();ui->txtDatabaseName->setEnabled(false);}
}

void EditMetadata::on_btnEditRef1_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditRef1->setEnabled(true);ui->txtRef1->setEnabled(true);}
    else{enableAll();ui->txtRef1->setEnabled(false);}
}

void EditMetadata::on_btnEditRef2_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditRef2->setEnabled(true);ui->txtRef2->setEnabled(true);}
    else{enableAll();ui->txtRef2->setEnabled(false);}
}

void EditMetadata::on_btnEditRef3_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditRef3->setEnabled(true);ui->txtRef3->setEnabled(true);}
    else{enableAll();ui->txtRef3->setEnabled(false);}
}
void EditMetadata::on_btnEditNumKeyPoints_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditNumKeyPoints->setEnabled(true);ui->txtNumKeyPoints->setEnabled(true);}
    else{enableAll();ui->txtNumKeyPoints->setEnabled(false);}
}
void EditMetadata::on_btnEditWarpSize_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditWarpSize->setEnabled(true);ui->txtWarpSize->setEnabled(true);}
    else{enableAll();ui->txtWarpSize->setEnabled(false);}
}

void EditMetadata::on_btnEditRelKeyDistance_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditRelKeyDistance->setEnabled(true);ui->txtRelKeyDistance->setEnabled(true);}
    else{enableAll();ui->txtRelKeyDistance->setEnabled(false);}
}

void EditMetadata::on_btnEditRedWeight_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditRedWeight->setEnabled(true);ui->txtRedWeight->setEnabled(true);}
    else{enableAll();ui->txtRedWeight->setEnabled(false);}
}

void EditMetadata::on_btnEditGreenWeight_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditGreenWeight->setEnabled(true);ui->txtGreenWeight->setEnabled(true);}
    else{enableAll();ui->txtGreenWeight->setEnabled(false);}
}

void EditMetadata::on_btnEditBlueWeight_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditBlueWeight->setEnabled(true);ui->txtBlueWeight->setEnabled(true);}
    else{enableAll();ui->txtBlueWeight->setEnabled(false);}
}

void EditMetadata::on_btnEditMaxDistance_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditMaxDistance->setEnabled(true);ui->txtMaxDistance->setEnabled(true);}
    else{enableAll();ui->txtMaxDistance->setEnabled(false);}
}
void EditMetadata::on_btnEditMinDistance_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditMinDistance->setEnabled(true);ui->txtMinDistance->setEnabled(true);}
    else{enableAll();ui->txtMinDistance->setEnabled(false);}
}

void EditMetadata::on_btnEditMinRatio_toggled(bool checked)
{
    if(checked){disableAll();ui->btnEditMinRatio->setEnabled(true);ui->txtMinRatioArea->setEnabled(true);}
    else{enableAll();ui->txtMinRatioArea->setEnabled(false);}
}

void EditMetadata::on_btnHelpNumKeyPoints_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Number of key points");
    msgBox.setText("A variable defining the number of key points to be extracted from the region of interest.The default number (35) is optimized for turtles. Keep in mind: too few key points is not distinctive enough. Too many may result in a computationally expensive comparison, while increasing the possibility of a false positive match between two fingerprints.\n\nChanging this value requires automatic re-extraction of the entire database.");
    msgBox.exec();
}

void EditMetadata::on_btnHelpWarpSize_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warp size");
    msgBox.setText("Photos are taken from various distances and close ups will show more detail than photos taken from a distance. The amount of detail influences the key point extraction. For example, a sharp close-up with many small sharp features may result in many small key points. However, these key points are not found in a photo of the same individual at a distance, resulting in a poor match between the two photos. This variable resolves this. First, the maximum distance is calculated between any two points in the region of interest. Next, each image is scaled (normalized) such that the maximum distance becomes equal to this variable. In this  way all images are standardized to the same size and approximately the same visible details.\n\nChanging this value requires automatic re-extraction of the entire database.");
    msgBox.exec();
}

void EditMetadata::on_btnHelpRelKeyDistance_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Relative key point distance");
    msgBox.setText("This variable defines the required minimum distance between two key points. In the default setting this is 5% of the maximum distance in the region of interest. Each key point has a \"response\" which is an indicator for key point quality. After extraction all key points are sorted, the key points with the highest response first. Next, for each key point is verified whether it is too close to a stronger key point. If this is the case, the key point is discarded. This variable is necessary to prevent areas with many key points. In these cases, the recognition algorithm cannot make a reliable match.\n\nChanging this value requires automatic re-extraction of the entire database.");
    msgBox.exec();
}

void EditMetadata::on_btnHelpRedWeight_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Red weight for gray image");
    msgBox.setText("The key points are not extracted from a color image but a gray scale image. I3S converts the color image to a gray scale or intensity image by adding the values for the red green and blue channel where each channel is multiplied by its corresponding weight. The sum of all three weights should be 1. For example a pixel with RGB values [100, 200, 160] and RGB weights {0.2;0.5;0.3] will result in a gray pixel value of 0.2x100 + 0.5x200 + 0.3x160 = 20 + 100 + 48 = 168. This setting is useful when processing specific types of photo settings. For example, under water red light diminishes quickest. On the other hand, if your animal has very distinctive red spots, you might try to only use the red channel. Experiments have shown that accuracy may increase significantly when choosing the right conversion. Please send us an e-mail at i3s@reijns.com when you need assistance.\n\nChanging this value requires automatic re-extraction of the entire database.");
    msgBox.exec();
}

void EditMetadata::on_btnHelpGreenWeight_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("The key points are not extracted from a color image but a gray scale image. I3S converts the color image to a gray scale or intensity image by adding the values for the red green and blue channel where each channel is multiplied by its corresponding weight. The sum of all three weights should be 1. For example a pixel with RGB values [100, 200, 160] and RGB weights {0.2;0.5;0.3] will result in a gray pixel value of 0.2x100 + 0.5x200 + 0.3x160 = 20 + 100 + 48 = 168. This setting is useful when processing specific types of photo settings. For example, under water red light diminishes quickest. On the other hand, if your animal has very distinctive red spots, you might try to only use the red channel. Experiments have shown that accuracy may increase significantly when choosing the right conversion. Please send us an e-mail at i3s@reijns.com when you need assistance.\n\nChanging this value requires automatic re-extraction of the entire database.");
    msgBox.exec();
}

void EditMetadata::on_btnHelpBlueWeight_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Blue weight for gray image");
    msgBox.setText("The key points are not extracted from a color image but a gray scale image. I3S converts the color image to a gray scale or intensity image by adding the values for the red green and blue channel where each channel is multiplied by its corresponding weight. The sum of all three weights should be 1. For example a pixel with RGB values [100, 200, 160] and RGB weights {0.2;0.5;0.3] will result in a gray pixel value of 0.2x100 + 0.5x200 + 0.3x160 = 20 + 100 + 48 = 168. This setting is useful when processing specific types of photo settings. For example, under water red light diminishes quickest. On the other hand, if your animal has very distinctive red spots, you might try to only use the red channel. Experiments have shown that accuracy may increase significantly when choosing the right conversion. Please send us an e-mail at i3s@reijns.com when you need assistance.\n\nChanging this value requires automatic re-extraction of the entire database.");
    msgBox.exec();
}

void EditMetadata::on_btnHelpMaxDistance_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Maximum allowed distance");
    msgBox.setText("This variable defines the maximum SQUARED distance between two matching key points relative to the maximum distance between any two reference points. In this case, 0.01 (10% squared) means 10% of this distance!!! This variable is used to prevent matches between key points which are too far apart.");
    msgBox.exec();
}

void EditMetadata::on_btnHelpMinDistance_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Minimum relative distance");
    msgBox.setText("This varible defines the minimum relative SQUARED distance between the best and second best matching key point. When comparing two fingerprints, i.e. two collections of key points, a key point from the first fingerprint might match with more than one key point from the second fingerprint. Usually, this happens more often in areas crowded with key points and this might result in a messy recognition. By demanding that the second best match is at a minimum distance of the best match, these messy recognitions are prevented improving the overall performance.\n\nFor example: the value is set to 1.5. Key point 1a (first fingerprint) matches with key point 2a and 2b (second fingerprint). The distance in recognition space between 1a and 2a is 9.5, and between 1a and 2b it is 8.1. The best match is therefore (1a, 2b). However, the relative distance between the two pairs is 9.5 / 8.1 = 1.173. Squared this distance is 1.173*1.173 = 1.376, which is less than 1.5. Therefore the match between 1a and 2b is discarded.");
    msgBox.exec();
}

void EditMetadata::on_btnHelpMinRatio_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Minimum ratio area");
    msgBox.setText("This variable defines the minimum relative difference in size of two matching key points. Each key point is a circle with a size. In recognition space, the two fingerprints are corrected for scale variations. Nevertheless, it is not likely that two key points are exactly equal in size. Far from that, the automatic key point extraction is often quite accurate in the location, but circle sizes have a significant variation. This variable sets a limit to the difference in circle size which is allowed.\n\nFor example: the value is set to 0.5. Key point 1 has a radius of 5, key point 2 has a radius of 4. The area of a circle = Pi * radius * radius, consequently the areas for key point 1 and 2 are 78.5 and 50.3 resp. The relative difference in size is therefore 50.3 / 78.5 = 0.64. Because 0.64 > 0.5 the size difference is acceptable.");
    msgBox.exec();
}
