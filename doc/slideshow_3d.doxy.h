/**
 * @defgroup SlideShow3D Photo Slide Show in 3D
 * @ingroup Modules
 *
 * Shows a collection of pictures on a rotating 3D sphere.
 *
 * With this module, you can create a nice animation showing pictures
 * from a disk folder.
 * For example, let's suppose you have 24 JPEG photos in the @c photos
 * folder. The following example
 *(<a href="examples/slideshow_3d.ddd">slideshow_3d.ddd</a>) will load
 * all the photos and show them on a slowly rotating sphere:
 * @include slideshow_3d.ddd
 *
 * @image html slideshow_3d.png "Output from slideshow_3d.ddd"
 *
 * Note that there is a template document that further illustrates this
 * module.
 * @{
 */



/**
 * The index of the next image to be added to the slide show.
 *
 * Just make sure you reset this variable to 0 before calling
 * @ref show_image in sequence (see the above example).
 */
integer image_index = 0;

/**
 * Whether to show back or front images.
 *
 * When this variable is 1.0, @ref show_image renders only the image on
 * the front of the sphere. When it is -1.0, @ref show_image renders
 * the images on the back of the sphere.
 */
real show_front = 1.0;

/**
 * The number of images locations on the surface of the sphere.
 * No more than @ref SHOWN images will be displayed simultaneously.
 */
integer SHOWN = 36;

/**
 * The width of each image.
 *
 * Images are scaled proportionally to fit the specified width in pixels.
 */
integer SIZE = 400;

/**
 * The rotation speed of the image sphere.
 *
 * The sphere rotates around the y axis at a speed of one turn every @ref SHOWN
 * seconds by default. To put it differently, a new image faces the viewer each
 * second.
 *
 * You may adjust the speed by changing @ref SPEED, which
 * acts as a multiplication factor.
 */
real SPEED = 1.0;

/**
 * The radius of the sphere.
 *
 * The radius of the sphere is in pixels.
 */
integer RADIUS = 1200;

/**
 * The total number of images.
 *
 * If @ref MAX is larger than the image collection, the slideshow will show a
 * gap as it rotates. If it is smaller, some images will overlap.
 */
integer MAX = 270;

/**
 * Adds an image to the collection and draw it if required.
 *
 * To create a slideshow, you call @ref show_image repeatedly for all the
 * files to be displayed. The @c with keyword and the @ref files builtin
 * are especially useful here:
 @code
show_image with files "*.jpg"
 @endcode
 *
 * Depending on the current parameter values, and the current page time,
 * @ref show_image will draw the image at the suitable location.
 */
show_image(filename:text);

/**
 * @}
 */
