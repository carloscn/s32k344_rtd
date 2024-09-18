1. Example Description
    This application demonstrates the usage of the Mcu Driver.
    The application includes an EB Tresos project that configures the BaseNXP, Dem, Mcu, Platform and Resource drivers.
    1.1 The application software functionality
        - Mcu_Init, Mcu_InitClock, Mcu_DistributePllClock, Mcu_SetMode
                Initialize the clock sources, the clock tree and configure the clock gating of peripheral
                Initialize two clock configurations with different STM0_CLK frequency: McuClockSettingConfig_0 with STM0_CLK = 48Mhz and McuClockSettingConfig_1 with STM0_CLK = 8Mhz.
                Using Mcu_GetClockFrequency to check the frequency of STM0_CLK after init clock.
        - Validation Point
            - Result = True (Verify that the Clock result returned corresponds to the expected value)
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - Daughter board: XS32K3X8CVB-Q289 PCB 53108 RevX3 SCH RevA1
            - Mother Board: X-S32K3XXX-MB PCB 47386 RevA SCH
            - Silicon: P32K358GVS 0P14E CTZF2233B
        2.1.2 Connections
            - Powered board through power Adapter 12V
        2.1.3 Debugger
            The Lauterbach debugger must be connected to J205 JTAG Cortex Debug connector.
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
                Ex: TRESOS_DIR = C:/EB/tresos29
            - GCC_DIR The path to the GCC instalation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.5/S32DS/build_tools/gcc_v10.2/gcc-10.2-arm32-eabi
            - PLUGINS_DIR The path to the RTD plugins directory
                Ex: PLUGINS_DIR = C:/NXP/SW32_RTD/eclipse/plugins
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
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
        To execute the example application from your command line execute make run. For executing the script in a T32 window already open the paths from run.cmm need to be changed relative to the debug folder instead of the example root folder.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
