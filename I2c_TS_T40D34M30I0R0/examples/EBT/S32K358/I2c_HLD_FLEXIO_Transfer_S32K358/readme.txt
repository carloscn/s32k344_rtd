1. Example Description
    This application demonstrates the usage of a subset of Real Time Drivers that are included in this code drop.
    The application includes an EB Tresos project that configures the Base, Dem, I2c, Mcu and Resource drivers.
    1.1 The application software functionality
            - I2c_Init
                    Initialization of i2c master and slave.
            - I2c_AsyncTransmit
                    Transfers asynchronous data.

2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - Daughter Card: XS32K3X8CVB-Q289 PCB 53108 RevX3 SCH RevA1
            - Mother Board : X-S32K3XXX-MB PCB 47386 RevA SCH
            - Silicon: P32K358GVS 0P14E CTZF2233B
        2.1.2 Connections
            - Connections: SDA: PTC29 - PTB27
                           SCL: PTC28 - PTB26
            - Pull up resistors of 2.2K each, one connected between SDA, SCL and VDD(J25.3).
        2.1.3 Debugger
            The debugger must be connected to J205 20-pin JTAG Cortex Debug connector.
    2.2 Software installation
        2.2.1 Tresos Project Installation
            The following procedure requires that the user has EB Tresos Studio installed and it is only needed for viewing, updating and generating the driver's configuration.
            Procedure:
                1. Make sure that all RTD plugins are already installed in the Tresos Studio plugins directory
                2. Open Tresos Studio
                3. Import example application project
                    a. Click on "File" and select "Import"
                    b. Select "Existing Projects into Workspace" and click on "Next" button
                    c. Select "Select root directory" and click on "Browse"
                    d. Select the location of the [project] folder in the installed example application package folder
                    e. Optional* - Select "Copy projects into workspace"
                    f. Click on "Finish" button
        2.2.2 Example configuration
            The following procedure requires that the user has EB Tresos Studio installed and the toolchains versions specified in the Release Notes.
            The toolchain that will be used needs to be installed for correct operation and the path to the installation location shall be added into the system environment variable(s):
            - TRESOS_DIR the installation path of Electrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos27
            - GCC_DIR The path to the GCC instalation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.5/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi
            - PLUGINS_DIR The path to the RTD plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Generating, building and running the example application
    For using the command line a make tool needs to be installed on your machine. For full functionality from command line sed is also required.
    3.1 Generating the Tresos project
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To generate the Tresos project of the example, execute the following command to build: make generate
            4. The output files of the generation shall be generated in the /generate subdirectory
    3.2 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subdirectory
    3.3 Running the application on the board
        To execute the example application load the executable file to the evaluation board using the Lauterbach debugger and the s32k3xx.cmm script.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
