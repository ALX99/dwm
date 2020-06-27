/** Function to shift the current view to the left/right
 *
 * @param: "arg->i" stores the number of tags to shift right (positive value)
 *          or left (negative value)
 */
void shiftview(const Arg *arg)
{
    Arg shifted;

    if (arg->i > 0) // left circular shift
        shifted.ui = (selmon->tagset[selmon->seltags] << arg->i) | (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));

    else // right circular shift
        shifted.ui = selmon->tagset[selmon->seltags] >> (-arg->i) | selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i);

    view(&shifted);
}

void shifttag(const Arg *arg)
{
    Arg shifted;

    if (arg->i > 0) // left circular shift
        shifted.i = (selmon->tagset[selmon->seltags] << arg->i) | (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));
    else // right circular shift
        shifted.i = selmon->tagset[selmon->seltags] >> (-arg->i) | (selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i));

    tag(&shifted);
    shiftview(arg); // Shift the view as well
}