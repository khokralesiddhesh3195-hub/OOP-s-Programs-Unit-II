// Include the file stream library for binary file operations.
#include <fstream>

// Include the input/output stream library.
#include <iostream>

// Use the standard namespace.
using namespace std;


// Define a structure for storing image metadata.
struct ImageMetadata
{
    // Store image width.
    int width;

    // Store image height.
    int height;

    // Store image format such as PNG or JPEG.
    char format[10];
};


// Main function where program execution begins.
int main()
{
    // Create the first image metadata record.
    ImageMetadata image1{1920, 1080, "PNG"};

    // Create the second image metadata record.
    ImageMetadata image2{1280, 720, "JPEG"};

    // Create the third image metadata record.
    ImageMetadata image3{3840, 2160, "PNG"};

    // Open images.bin in binary mode for writing.
    ofstream output("images.bin", ios::binary);

    // Check whether the binary file opened successfully.
    if (!output)
    {
        // Display an error message if opening failed.
        cerr << "Unable to open binary file for writing." << endl;

        // Terminate the program with an error code.
        return 1;
    }

    // Write the first image record into the binary file.
    output.write(
        reinterpret_cast<const char*>(&image1),
        sizeof(ImageMetadata)
    );

    // Write the second image record into the binary file.
    output.write(
        reinterpret_cast<const char*>(&image2),
        sizeof(ImageMetadata)
    );

    // Write the third image record into the binary file.
    output.write(
        reinterpret_cast<const char*>(&image3),
        sizeof(ImageMetadata)
    );

    // Close the binary output file.
    output.close();

    // Open images.bin in binary mode for reading.
    ifstream input("images.bin", ios::binary);

    // Check whether the binary file opened successfully.
    if (!input)
    {
        // Display an error message if opening failed.
        cerr << "Unable to open binary file for reading." << endl;

        // Terminate the program with an error code.
        return 1;
    }

    // Create an empty object to hold each record while reading.
    ImageMetadata item{};

    // Start record numbering from 1.
    int recordNo = 1;

    // Display the heading of the image metadata report.
    cout << "=== Image Metadata ===" << endl;

    // Read one complete ImageMetadata record at a time.
    while (input.read(
        reinterpret_cast<char*>(&item),
        sizeof(ImageMetadata)))
    {
        // Display the current record number.
        cout << "Record " << recordNo++ << ": ";

        // Display image width and height.
        cout << item.width << " x " << item.height;

        // Display the image format.
        cout << " | " << item.format << endl;
    }

    // Close the binary input file.
    input.close();

    // Return 0 to indicate successful execution.
    return 0;
}

🖥️ Sample Output
=== Image Metadata ===
Record 1: 1920 x 1080 | PNG
Record 2: 1280 x 720 | JPEG
Record 3: 3840 x 2160 | PNG
