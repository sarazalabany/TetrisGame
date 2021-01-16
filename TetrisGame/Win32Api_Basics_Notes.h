#ifndef WIN32API_BASICS_NOTES_H
#define WIN32API_BASICS_NOTES_H



/*--------------------------------------------------------------- Win32 API --------------------------------------------------
 *The Win32 API (also called the Windows API) is the original platform for native C/C++ Windows applications that require direct
 *access to Windows and hardware. It provides a first-class development experience without depending on a managed runtime
 * environment like .NET and WinRT (for UWP apps for Windows 10).
 * This makes the Win32 API the platform of choice for applications that need the highest level of performance and direct access to system hardware.
 *
 *
 *
 *
 *Windows are objects—they have both code and data—but they are not C++ classes. Instead, a program references a window by using
 *a value called a handle. A handle is an opaque type. Essentially, it is just a number that the operating system uses to identify an object.
 * You can picture Windows as having a big table of all the windows that have been created. It uses this table to look up windows by their handles.
 *  (Whether that's exactly how it works internally is not important.) The data type for window handles is HWND, which is usually pronounced "aitch-wind."
 *   Window handles are returned by the functions that create windows:
 *
 *  Coordinates are measured in device-independent pixels. We'll have more to say about the device
 *  independent part of device-independent pixels when we discuss graphics.

 * Depending on your task, you might measure coordinates relative to the screen,
 * relative to a window (including the frame), or relative to the client area of a window.
 * For example, you would position a window on the screen using screen coordinates, but you would draw inside
 * a window using client coordinates. In each case, the origin (0, 0) is always the top-left corner of the region.
 * https://docs.microsoft.com/en-us/windows/win32/learnwin32/images/coordinates01.png
 *
 *
 *
 *----------------------------------------------Overview of the Windows Graphics Architecture-------------------------:
 *---------- check this url:::::: ----->>https://docs.microsoft.com/en-us/windows/win32/learnwin32/overview-of-the-windows-graphics-architecture----------------------------
 *https://docs.microsoft.com/en-us/windows/win32/learnwin32/images/graphics01.png
 *
 *Graphics Device Interface (GDI) is the original graphics interface for Windows. GDI was first written for 16-bit Windows and then updated for 32-bit and 64-bit Windows.
 *Direct3D supports 3-D graphics.
* Direct2D is a modern API for 2-D graphics, the successor to both GDI and GDI+.
* DirectWrite is a text layout and rasterization engine. You can use either GDI or Direct2D to draw the rasterized text.
 *DirectX Graphics Infrastructure (DXGI) performs low-level tasks, such as presenting frames for output. Most applications do not use DXGI directly. Rather, it serves as an intermediate layer between the graphics driver and Direct3D.
 *
 *-----------------------------------------------Hardware Acceleration------------------------------------------------------
 *The term hardware acceleration refers to graphics computations performed by the graphics processing unit (GPU),
 * rather than the CPU. Modern GPUs are highly optimized for the types of computation used in rendering graphics.
 *  Generally, the more of this work that is moved from the CPU to the GPU, the better.
 *
 *
 *GDI has limited support for alpha-blending. Most GDI functions do not support alpha blending,
 *although GDI does support alpha blending during a bitblt operation. GDI+ supports transparency,
 *but the alpha blending is performed by the CPU, so it does not benefit from hardware acceleration.
*Hardware-accelerated alpha-blending also enables anti-aliasing.
*Aliasing is an artifact caused by sampling a continuous function. For example,
* when a curved line is converted to pixels, aliasing can cause a jagged appearance.[3]
*  Any technique that reduces the artifacts caused by aliasing is considered a form of anti-aliasing.
*  In graphics, anti-aliasing is done by blending edges with the background. For example, here is a circle drawn by GDI and the same circle drawn by Direct2D.
 *
 *
 *---------------------------------------------- MFC ---------------------------------------------------------------------------
*The Microsoft Foundation Class (MFC) Library provides an object-oriented wrapper over much of the Win32 and COM APIs. Although it
 *can be used to create very simple desktop applications, it is most useful when you need to develop more complex user
 * interfaces with multiple controls. You can use MFC to create applications with Office-style user interfaces. For documentation on the Windows platform itself,
 *see Windows documentation. For information on building Windows applications in C++ without MFC, see Build desktop Windows apps using the Win32 API.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#endif // WIN32API_BASICS_NOTES_H
